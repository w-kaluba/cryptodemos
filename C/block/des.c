/*
The following is a C program implementing the DES cipher.
The user specifies the input file, key and output file.

There are multiple steps to the process. 
- First an initial permutation is applied. This isn't of
cryptographic siginificance but is useful when implementing the cipher in
hardware.

- One of the halves is expanded into 48 bits via the expansion permutaion.
- This is then XOR'd with the first round of the key.
- This is then processed by the eight S-Boxes which replace their six input
bits according to a lookup table.
- Finally the reuslts of the S-Boxes are then permuted.
- This process is then repeated with alternating halves using the rest of the key
according to the key schedule to complete one round of DES.
 */

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>

int key_permutation(int);
int initial_permutation(int);
int s_box(int, int);
int expansion_permutation(int);
int feistel(int, int);
void usage_warning();

int main(int argc, char *argv[])
{
}