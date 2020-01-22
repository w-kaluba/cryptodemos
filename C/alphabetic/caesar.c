/*****************************************************************
* A simple implementation of the Caesar cipher using a basic CLI.
* The user inputs the encryption shift amount as well as the filename of
* the ciphertext as the CL arguments when running the program.
* The program then outputs an encrypted ciphertext which can be piped
* into a file for later reference.
*****************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void usage_warning();
char caesar_shift(char, int);

int main(int argc, char *argv[])
{
    FILE *ciphertext;
    char *outputfile;
    FILE *plaintext;
    char *buffer = malloc(256);
    int shift_amount = atoi(argv[1]);

    // Checking for the current number of arguments.
    if (argc < 3)
    {
        usage_warning();
    }

    plaintext = fopen(argv[2], "r");
    ciphertext = fopen(arg)

        while (fgets(buffer, 256, plaintext))
    {
        int limit = strlen(buffer);
        for (int i = 0; i < limit; i++)
        {
            if (isalpha(buffer[i]))
            {
                buffer[i] = caesar_shift(buffer[i], shift_amount);
            }
        }
    }
}

char caesar_shift(char letter, int shift)
{
    char output;
}

void usage_warning()
{
    //Displays a warning to the user to explain usage of the program
    printf("Usage:\t./caesar [input_filename] [shift amount]")
}