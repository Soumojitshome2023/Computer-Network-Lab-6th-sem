/*
2. Write a C code to decode a user provided codeword using CRC procedure.
Test Case:
Input:
Codeword: 100100001
Generator: 1101
Output:
Original data received
Actual data: 1 0 0 1 0 0
*/

#include <stdio.h>
#include <string.h>

// Function to perform XOR of two binary bits
char xorBit(char a, char b)
{
    return (a == b) ? '0' : '1';
}

int main()
{
    char codeword[200], generator[100], temp[200], remainder[100];

    printf("Enter the codeword: ");
    scanf("%s", codeword);

    printf("Enter the generator (polynomial): ");
    scanf("%s", generator);

    int codeLen = strlen(codeword);
    int genLen = strlen(generator);

    // Step 1: Copy codeword to temp for processing
    strcpy(temp, codeword);

    // Step 2: Perform CRC division (XOR with generator)
    for (int i = 0; i <= codeLen - genLen; i++)
    {
        if (temp[i] == '1')
        {
            for (int j = 0; j < genLen; j++)
            {
                temp[i + j] = xorBit(temp[i + j], generator[j]);
            }
        }
    }

    // Step 3: Extract remainder from temp (last genLen - 1 bits)
    int isValid = 1;
    for (int i = codeLen - genLen + 1; i < codeLen; i++)
    {
        if (temp[i] != '0')
        {
            isValid = 0; // Error in transmission
            break;
        }
    }

    // Step 4: Output result
    if (isValid)
    {
        printf("\nOriginal data received\n");
        printf("Actual data: ");
        for (int i = 0; i < codeLen - (genLen - 1); i++)
        {
            printf("%c ", codeword[i]);
        }
        printf("\n");
    }
    else
    {
        printf("\nData corrupted\n");
    }

    return 0;
}
