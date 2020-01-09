import random  # importing the math library to generate random numbers
import math


def fermat_test(N, k):
    """
    Implements the Fermat test for primality,
    N is the number to be tested and k is the number of times to test it.
    """

    for i in range(k):
        a = random.randint(2, N - 1)
        if (pow(a, N - 1, N) == 1):
            continue
        else:
            return False
    return True


def miller_rabin_test(N, k):
    """
    Implements the Miller Rabin test for primality, N is the integer
    to be tested and k is the number of times to test it
    """

    d = N
    r = 0
    while(True):
        if (d % 2 == 0):
            d /= 2
            r += 1
        else:
            break

    candidates = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37]

    for a in candidates[:k]:
        x = pow(a, d, N)
        if (x == 1 or x == N - 1):
            continue
        for i in range(r - 1):
            x = pow(x, 2, N)
            if x == N - 1:
                continue
            return False
    return True


def generate_prime(N):
    """
    Generates a prime of size at least N to use as a modulus for the DFH Key Exchange
    """

    prime_found = False

    while (prime_found == False):
        number = random.randint(N, 100*N)  # First we generate a random number
        if (fermat_test(number, 3)) and miller_rabin_test(number, 5):  # Then we implement some tests
            prime_found = True
            return number
