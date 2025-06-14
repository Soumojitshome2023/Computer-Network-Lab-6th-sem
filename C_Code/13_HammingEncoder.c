/*
1. Write a C code to encode a user provided dataword using Hamming Code.
Example:
Input:  1100101
Output: No of redundant bits: 4
        The codeword is: 11000101100
*/

#include <stdio.h>
#include <string.h>

#define MAX 100

// Function to calculate number of redundant bits required
int calculateRedundantBits(int m)
{
    int r = 0;
    while ((1 << r) < (m + r + 1))
    {
        r++;
    }
    return r;
}

int main()
{
    char dataword[MAX], codeword[MAX];
    int dataLen, r, totalLen;

    printf("Enter the dataword (binary): ");
    scanf("%s", dataword);

    dataLen = strlen(dataword);
    r = calculateRedundantBits(dataLen); // number of parity bits
    totalLen = dataLen + r;              // total length = data + parity

    // Initialize codeword with 0s
    for (int i = 0; i < totalLen; i++)
    {
        codeword[i] = '0';
    }

    // Place data bits in codeword (skip parity positions)
    for (int i = 0, j = 0; i < totalLen; i++)
    {
        if ((i + 1) & (i))
        { // position not a power of 2
            codeword[i] = dataword[j++];
        }
    }

    // Calculate parity bits
    for (int i = 0; i < r; i++)
    {
        int pos = (1 << i) - 1;
        int count = 0;

        for (int j = pos; j < totalLen; j++)
        {
            if (((j + 1) & (1 << i)) && codeword[j] == '1')
            {
                count++;
            }
        }

        codeword[pos] = (count % 2) + '0'; // set parity bit
    }

    codeword[totalLen] = '\0'; // null terminate

    // Output
    printf("\nResults:\n");
    printf("No of redundant bits: %d\n", r);
    printf("The codeword is: %s\n", codeword);

    return 0;
}
