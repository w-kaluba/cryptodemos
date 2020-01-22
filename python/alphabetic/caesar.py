"""
A simple demonstration of the alphabetic caesar cipher.
"""


def caesar(plaintext, key):
    """
    The function takes a string as the plaintext
    and integer (0-25) as the key, returning an ecnrypted string
    as the result
    """
    result = ""
    for letter in plaintext:
        if letter.isalpha():
            cipher = ord(letter) + int(key)
            result += chr(cipher)
        else:
            result += letter

    return result


if __name__ == "__main__":
    key = input("Enter a key:")
    message = input("And then enter a message...")

    ciphertext = caesar(message, key)
    print(f"Your encrypted text is:\n {ciphertext}")
