/*
1. Write a C code to encode a user provided dataword using Even and Odd Parity bit procedure.
[Take a bit stream as input. Find even parity bit, even parity codeword and odd parity bit, odd parity
codeword.]
*/

#include <stdio.h>
#include <string.h>

// Function to calculate parity bit
char calculateParityBit(const char data[], int isEven)
{
    int count = 0;
    for (int i = 0; data[i] != '\0'; i++)
    {
        if (data[i] == '1')
        {
            count++;
        }
    }

    // Return appropriate parity bit based on parity type
    if (isEven)
    {
        return (count % 2 == 0) ? '0' : '1';
    }
    else
    {
        return (count % 2 == 1) ? '0' : '1';
    }
}

int main()
{
    char dataword[100];
    char evenCodeword[101], oddCodeword[101]; // one extra for parity bit

    printf("Enter the dataword (binary string): ");
    scanf("%s", dataword);

    // Validate input
    for (int i = 0; dataword[i] != '\0'; i++)
    {
        if (dataword[i] != '0' && dataword[i] != '1')
        {
            printf("Error: Input must contain only 0s and 1s\n");
            return 1;
        }
    }

    // Calculate parity bits
    char evenParityBit = calculateParityBit(dataword, 1);
    char oddParityBit = calculateParityBit(dataword, 0);

    // Create codewords by appending the parity bits
    strcpy(evenCodeword, dataword);
    int len = strlen(evenCodeword);
    evenCodeword[len] = evenParityBit;
    evenCodeword[len + 1] = '\0';

    strcpy(oddCodeword, dataword);
    oddCodeword[len] = oddParityBit;
    oddCodeword[len + 1] = '\0';

    // Display results
    printf("\nResults:\n");
    printf("Original dataword: %s\n", dataword);
    printf("Even parity bit: %c\n", evenParityBit);
    printf("Even parity codeword: %s\n", evenCodeword);
    printf("Odd parity bit: %c\n", oddParityBit);
    printf("Odd parity codeword: %s\n", oddCodeword);

    return 0;
}
