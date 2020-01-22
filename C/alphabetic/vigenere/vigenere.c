/*****************************************************************
* A simple implementation of the vigenere cipher using a basic CLI.
* The user enters the input file and the key as well as the filename for
* the output as the CL arguments when running the program.
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
    char *outputfile;
    char *key;
    char *buffer;

    // Checking for the current number of arguments.
    if (argc < 3)
    {
        usage_warning();
        return 1;
    }

    outputfile = (char *)malloc(32);
    key = argv[2];

    // Opening input and output files
    plaintext = fopen(argv[1], "r");
    strcpy(outputfile, argv[3]);
    ciphertext = fopen(outputfile, "w");

    //Iterating through the input file line by line
    if (plaintext != NULL && ciphertext != NULL)
    {
        buffer = (char *)malloc(256);
        int counter = 0;
        int key_length = strlen(key);

        while (fgets(buffer, 255, plaintext))
        {
            int limit = strlen(buffer);
            for (int i = 0; i < limit; i++)
            {
                if (isalpha(buffer[i]))
                {
                    buffer[i] = caesar_shift(buffer[i], (tolower(key[counter % key_length]) - 'a'));
                    counter++;
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
    printf("Usage:\t./vigenere [input_filename] [key] [output_filename]");
}