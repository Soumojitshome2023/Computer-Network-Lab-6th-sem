/*
1. Write a C code to encode a user provided dataword using CRC procedure.

Test Case 1:
Input:
Dataword: 100100
Generator: 1101
Output:
Updated dividend: 100100000
Remainder: 001
The codeword is: 100100001
*/

#include <stdio.h>
#include <string.h>

// Perform XOR between two binary characters
char xorBit(char a, char b)
{
    return (a == b) ? '0' : '1';
}

int main()
{
    char dataword[100], generator[100];
    char dividend[200], remainder[100], codeword[200];

    printf("Enter the dataword: ");
    scanf("%s", dataword);

    printf("Enter the generator (polynomial): ");
    scanf("%s", generator);

    int dataLen = strlen(dataword);
    int genLen = strlen(generator);

    // Step 1: Append (genLen - 1) zeros to dataword to create dividend
    strcpy(dividend, dataword);
    for (int i = 0; i < genLen - 1; i++)
    {
        dividend[dataLen + i] = '0';
    }
    dividend[dataLen + genLen - 1] = '\0';

    printf("\nUpdated dividend: %s\n", dividend);

    // Step 2: Perform division (XOR with generator)
    char temp[200];
    strcpy(temp, dividend);

    for (int i = 0; i <= strlen(dividend) - genLen; i++)
    {
        if (temp[i] == '1')
        {
            for (int j = 0; j < genLen; j++)
            {
                temp[i + j] = xorBit(temp[i + j], generator[j]);
            }
        }
    }

    // Step 3: Extract remainder (last genLen-1 bits)
    for (int i = 0; i < genLen - 1; i++)
    {
        remainder[i] = temp[strlen(dividend) - genLen + 1 + i];
    }
    remainder[genLen - 1] = '\0';

    // Step 4: Final codeword = dataword + remainder
    strcpy(codeword, dataword);
    strcat(codeword, remainder);

    printf("Remainder: %s\n", remainder);
    printf("The codeword is: %s\n", codeword);

    return 0;
}
