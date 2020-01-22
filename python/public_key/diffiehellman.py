"""
The Diffie-Hellman key exchange is a process that allows users to exchange a secret key
to use in a symmetric key encryption system. The security of this problem is equivalent to solving the
discrete logarithm problem.
"""
import algorithms.primes as primes
import random

p = primes.generate_prime(2 ** 32)
g = random.randint(2, p - 2)
a = random.randint(2, p - 2)

c = pow(g, a, p)
print(c)
