/*****************************************************************
* A simple implementation of the Affine cipher using a basic CLI.
* The user inputs the key as well as the filename of
* the ciphertext as the CL arguments when running the program.
*****************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void usage_warning();
char affine_shift(char, int, int);

int main(int argc, char *argv[])
{
    FILE *ciphertext;
    FILE *plaintext;
    char *outputfile = (char *)malloc(32);
    char *buffer;

    // Checking for the current number of arguments.
    if (argc < 3 || argv[2] == 0)
    {
        usage_warning();
        return 1;
    }
    int mult_amount = atoi(argv[2]);
    int shift_amount = atoi(argv[3]);

    // Opening input and output files
    plaintext = fopen(argv[1], "r");
    strcpy(outputfile, argv[4]);
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
                    buffer[i] = affine_shift(buffer[i], mult_amount, shift_amount);
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

char affine_shift(char letter, int mult, int shift)
{
    // Assumes the input is alphabetic.
    char output;
    if (isupper(letter))
    {
        output = 'A' + (((((letter - 'A') * mult) % 26) + shift) % 26);
    }
    else if (islower(letter))
    {
        output = 'a' + (((((letter - 'a') * mult) % 26) + shift) % 26);
    }
}

void usage_warning()
{
    //Displays a warning to the user to explain usage of the program
    printf("Usage:\t./caesar [input_filename] [a] [b] [output_filename]");
}