"""
## Outline
DES is the symmetric encryption scheme developed in the 1970s in IBM and refined by the NSA.
There are multiple steps to the process:
- First the input is split into two 32 bit halves
- One of the halves is expanded to 48 bits via the expansion permutation
- This is then XOR'd with the first round of the key
- This is then processed by the eight S-boxes which replace their six input bits with four output bits according to a lookup table
- Finally the results of the S-Boxes are permuted so that each S-Box affects four others in the next round

There are also initial and final permutations that rearrange the bits
## Key Schedule
- The initial key is 64 bits but every 8th bit is discarded to produce a 56-bit key
-
"""


def i_perm(x):
    """
    Takes a 64-bit input and performs the initial permutation of DES
    """
    pass


def s_box(i, x):
    """
    Implements the S box part of the DES algorithm. The variable i is an index, indicating which s box to simulate.
    x is the 48-bit input, with the s box in question only affecting the correct 6 bits and producing a 4-bit output.
    """
    pass


def f_expand(x):
    """
    The expansion part of the feistel function, it takes a 32-bit int as input
    and outputs a 48-bit int.
    """
    pass


def feistel(x, subkey):
    """
    Takes a 32-bit integer as an input and applies the DES Feistel function.
    """
    x_48 = f_expand(x)
    s_input = x_48 ^ subkey
    output = []
    for i in range(8):
        block = s_box(i, s_input)
        output.append(block)
