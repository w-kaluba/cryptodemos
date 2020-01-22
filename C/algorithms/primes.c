/***********************************************************************
 * A simple program for generating prime numbers randomly.
 * These primes can then be used in other cryptographic functions like
 * the Diffie Hellman Key Exchange and RSA.
 * *********************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <time.h>
#include <math.h>

int mod_exp(int, int, int);
bool fermat_test(int, int);
bool miller_rabin_test(int, int);

int main(int argc, char *argv[])
{
    //The main method simply generates primes
    srand(time(0));
    int number = 0;
    bool prime_found = false;
    while (prime_found == false)
    {
        number = rand();
        // printf("%i\n", number);
        // prime_found = true;
        if (fermat_test(number, 3) && miller_rabin_test(number, 5))
        {
            prime_found = true;
            printf("Your prime is:\t %i", number);
        }
    }
    return 0;
}

int mod_exp(int a, int m, int base)
{
    int result = 0;
    int k = floor(log2(a));
    int b = a;
    while (k >= 0)
    {
        b = (b * b) % base;
        if ((1 << k) & m)
        {
            b = (b * a) % base;
        }
        k--;
    }

    return b;
}

bool fermat_test(int N, int k)
{
    for (int i = 0; i < k; i++)
    {
        int a = rand() % N;
        if (mod_exp(a, N - 1, N) == 1)
        {
            continue;
        }
        else
        {
            return false;
        }
    }
}

bool miller_rabin_test(int N, int k)
{
    int d = N;
    int r = 0;
    while (true)
    {
        if (d % 2 == 0)
        {
            d /= 2;
            r++;
        }
        else
        {
            break;
        }
    }
    int candidates[12] = {2,
                          3,
                          5,
                          7,
                          11,
                          13,
                          17,
                          19,
                          23,
                          31,
                          37};
    k = (k < 12) ? k : 12;

    for (int i = 0; i < k; i++)
    {
        int test = candidates[i];
        int x = mod_exp(test, d, N);
        if (x == 1 || x == N - 1)
        {
            continue;
        }
        for (int j = 0; j < r - 1; j++)
        {
            x = mod_exp(x, 2, N);
            if (x == N - 1)
            {
                continue;
            }
            return false;
        }
        return true;
    }
}