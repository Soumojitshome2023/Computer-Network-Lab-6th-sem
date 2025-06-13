/*
2. Write a C code to decode a user provided codeword using Checksum procedure.
Provide the output along with original data (good/bad).

Input:
Codeword: 1100110010101010111100001100001111010011
Segment Length = 8

Output:
Data is correct (GOOD)
OR
Data is incorrect (BAD)
*/

#include <stdio.h>
#include <string.h>

#define MAX 200

// Function to add two binary segments
void addBinary(char a[], char b[], char result[], int len)
{
    int carry = 0;
    for (int i = len - 1; i >= 0; i--)
    {
        int sum = (a[i] - '0') + (b[i] - '0') + carry;
        result[i] = (sum % 2) + '0';
        carry = sum / 2;
    }

    // If carry is left, wrap around and add again
    while (carry)
    {
        char wrap[33];
        for (int i = 0; i < len - 1; i++)
            wrap[i] = '0';
        wrap[len - 1] = '1';
        wrap[len] = '\0';

        char temp[33];
        strcpy(temp, result);

        carry = 0;
        for (int i = len - 1; i >= 0; i--)
        {
            int sum = (temp[i] - '0') + (wrap[i] - '0') + carry;
            result[i] = (sum % 2) + '0';
            carry = sum / 2;
        }
    }
}

// Function to take 1's complement of a binary string
void onesComplement(char bin[], int len)
{
    for (int i = 0; i < len; i++)
    {
        bin[i] = (bin[i] == '0') ? '1' : '0';
    }
    bin[len] = '\0';
}

int main()
{
    char codeword[MAX];
    int segmentLength;

    printf("Enter the received codeword (data + checksum): ");
    scanf("%s", codeword);

    printf("Enter the segment length: ");
    scanf("%d", &segmentLength);

    int len = strlen(codeword);

    if (len % segmentLength != 0)
    {
        printf("Error: Codeword length must be divisible by segment length.\n");
        return 1;
    }

    // Initialize sum = 0000..000
    char sum[33] = {0};
    for (int i = 0; i < segmentLength; i++)
        sum[i] = '0';
    sum[segmentLength] = '\0';

    char segment[33], temp[33];

    // Add each segment including checksum
    for (int i = 0; i < len; i += segmentLength)
    {
        for (int j = 0; j < segmentLength; j++)
            segment[j] = codeword[i + j];
        segment[segmentLength] = '\0';

        addBinary(sum, segment, temp, segmentLength);
        strcpy(sum, temp);
    }

    // Take 1's complement
    onesComplement(sum, segmentLength);

    // Check if result is all 0s
    int isError = 0;
    for (int i = 0; i < segmentLength; i++)
    {
        if (sum[i] != '0')
        {
            isError = 1;
            break;
        }
    }

    if (isError)
        printf("Data is incorrect (BAD)\n");
    else
        printf("Data is correct (GOOD)\n");

    return 0;
}
