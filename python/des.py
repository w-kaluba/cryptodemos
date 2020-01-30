"""
# Outline
DES is the symmetric encryption scheme developed in the 1970s in IBM and refined by the NSA.
There are multiple steps to the process:
- First the input is split into two 32 bit halves
- One of the halves is expanded to 48 bits via the expansion permutation
- This is then XOR'd with the first round of the key
- This is then processed by the eight S-boxes which replace their six input bits with four output bits according to a lookup table
- Finally the results of the S-Boxes are permuted so that each S-Box affects four others in the next round

There are also initial and final permutations that rearrange the bits
# Key Schedule
- The initial key is 64 bits but every 8th bit is discarded to produce a 56-bit key
- There is then a permutation applied where each bit is substituted with the bit of row*8 + column
- Before the round sub-key is selected each there is a key rotation applied depending on which round of the schedule it is
- The key is then compressed via a further permutation following the same rule as above
This 48-bit key is then returned as the key for that round.
"""

# It probably makes sense to have a random key generator function here


def key_permutation1(key):
    """
    Takes a 64-bit key as input and returns a 56 bit key as an integer. By dropping every eight bit
    """
    key56 = 0
    for i in range(8):
        row = (int(key) & 0xfe << (8*(7-i))) >> ((8 * (7-i)) + 1)
        print(format(row, '07b'))
        key56 += row << (7*(7 - i))
    return key56


def key_permutation2(key):
    """
    Takes a 56-bit key as input and returns the key permuted according to the following rule:
    Each bit is substituted with the bit of row*8 + column
    where the key is arrange into a grid of 7 rows and 8 columns.
    Thus the row number is given by bit number // 8 and the column number is given by bit number % 7git ad.
    This could be implemented using arrays or using ints but I'm going to do ints because there's less overhead in python.
    """
    key56 = 0
    for i in range(64):
        bit = 1 << i
        row = i // 7
        column = i % 8
        position = (row * 8 + column) % 64


print(format(0xfefefefefefefefe, '064b'))
print(format(key_permutation1(0xfefefefefefefefe), '056b'))


def i_perm(x):
    """
    Takes a 64-bit input and performs the initial permutation of DES.
    The output is another 64-bit integer.
    """

    # The long term plan is to refactor these permutation reference tables into text files
    perm_table = [58, 50, 42, 34, 26, 18, 10, 2, 60, 52, 44, 36, 28, 20, 12, 4, 62, 54, 46, 38, 30, 22, 14, 6, 64, 56, 48, 40, 32, 24,
                  16, 8, 57, 49, 41, 33, 25, 17, 9, 1, 59, 51, 43, 35, 27, 19, 11, 3, 61, 53, 45, 37, 29, 21, 13, 5, 63, 55, 47, 39, 31, 23, 15, 7]
    input_value = format(x, '064b')
    output = [] + ['']*64
    for i in range(len(input_value)):
        output[i] = input_value[perm_table[i] - 1]
    return "".join(output)


def s_box(i, x):
    """
    Implements the S box part of the DES algorithm. The variable i is an index, indicating which s box to simulate.
    x is the 48-bit input, with the s box in question only affecting the correct 6 bits and producing a 4-bit output.
    """
    sub_perm = {'0': [],
                '1': [],
                '2': [],
                '3': []}

    with open("s_box_table.txt", 'r') as lookup_table:
        lookup_table.seek(53*4*(i-1))
        for key in sub_perm:
            sub_perm[key] = lookup_table.readline().split()

    col = ((x & 0b100000) >> 5) + (x & 0b1)
    row = (x & 0b011110) >> 1

    return sub_perm[str(col)][row]


def p_box(x):
    pass


def f_expand(x):
    """
    The expansion part of the feistel function, it takes a 32-bit int as input
    and outputs a 48-bit int.
    """
    return 1


def feistel(x, subkey):
    """
    Takes a 32-bit integer as an input and applies the DES Feistel function.
    """
    x_48 = f_expand(x)
    s_input = x_48 ^ subkey
    output = []  # Need to work out some way to recombine the outputs of the s boxes
    for i in range(8):
        block = s_box(i, s_input)
        output.append(block)

    p_box(output)
