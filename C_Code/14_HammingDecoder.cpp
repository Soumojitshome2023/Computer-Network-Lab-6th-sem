/*
Question: Write a C code to decode a user provided codeword using Hamming Code procedure.
*/

#include <stdio.h>
#include <string.h>

#define MAX 100

// Function to detect and correct single-bit error in Hamming code
int detectAndCorrectError(char codeword[])
{
    int len = strlen(codeword);
    int r = 0;

    // Find how many parity bits exist
    while ((1 << r) < len + 1)
    {
        r++;
    }

    int errorPos = 0;

    // Check parity bits
    for (int i = 0; i < r; i++)
    {
        int mask = 1 << i;
        int count = 0;

        for (int j = 0; j < len; j++)
        {
            if ((j + 1) & mask)
            {
                if (codeword[j] == '1')
                {
                    count++;
                }
            }
        }

        if (count % 2 != 0)
        {
            errorPos += mask;
        }
    }

    // Correct the bit if error exists
    if (errorPos >= 1 && errorPos <= len)
    {
        codeword[errorPos - 1] = (codeword[errorPos - 1] == '0') ? '1' : '0';
    }

    return errorPos;
}

int main()
{
    char codeword[MAX], original[MAX];

    printf("Enter the codeword (binary string): ");
    scanf("%s", codeword);

    // Validate input
    for (int i = 0; codeword[i] != '\0'; i++)
    {
        if (codeword[i] != '0' && codeword[i] != '1')
        {
            printf("Error: Codeword must contain only 0s and 1s\n");
            return 1;
        }
    }

    strcpy(original, codeword); // keep a copy of original input
    int errorPosition = detectAndCorrectError(codeword);

    if (errorPosition == 0)
    {
        printf("\nActual data received\n");
    }
    else
    {
        printf("\nWrong data received\n");
        printf("Error at position %d\n", errorPosition);
        printf("Corrected codeword is: %s\n", codeword);
    }

    return 0;
}
