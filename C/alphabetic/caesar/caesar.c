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
    FILE *plaintext;
    char *outputfile = (char *)malloc(32);
    char *buffer;
    printf("break1");
    // Checking for the current number of arguments.
    if (argc < 3)
    {
        usage_warning();
        return 1;
    }
    int shift_amount = atoi(argv[2]);

    // Opening input and output files
    plaintext = fopen(argv[1], "r");
    strcpy(outputfile, argv[3]);
    ciphertext = fopen(outputfile, "w");

    //Iterating through the input file line by line
    if (plaintext != NULL && ciphertext != NULL)
    {
        buffer = (char *)malloc(256);
        while (fgets(buffer, 255, plaintext))
        {
            int limit = strlen(buffer);
            for (int i = 0; i < limit; i++)
            {
                if (isalpha(buffer[i]))
                {
                    buffer[i] = caesar_shift(buffer[i], shift_amount);
                }
            }
            fwrite(buffer, sizeof(char), limit, ciphertext);
        }
        //Clean up
        fclose(plaintext);
        fclose(ciphertext);
        free(buffer);
    }
    else
    {
        return 2;
    }
}

char caesar_shift(char letter, int shift)
{
    // Assumes the input is alphabetic.
    char output;
    if (isupper(letter))
    {
        output = 'A' + (((letter - 'A') + shift) % 26);
    }
    else if (islower(letter))
    {
        output = 'a' + (((letter - 'a') + shift) % 26);
    }
}

void usage_warning()
{
    //Displays a warning to the user to explain usage of the program
    printf("Usage:\t./caesar [input_filename] [shift amount] [output_filename]");
}