/*
1. Write a C code to encode a user provided dataword using checksum procedure.
Input:
Dataword: 11001100101010101111000011000011
Segment Length = 8
Output:
Checksum: 11010011
Code word : 1100110010101010111100001100001111010011
*/

#include <stdio.h>
#include <string.h>

#define MAX 200 // Maximum input size

// Function to add two binary strings (bit-by-bit)
// Handles carry and wrap-around if overflow occurs
void addBinary(char a[], char b[], char result[], int len)
{
    int carry = 0;
    // Start from rightmost bit and move left
    for (int i = len - 1; i >= 0; i--)
    {
        int bitA = a[i] - '0'; // convert char to int
        int bitB = b[i] - '0';
        int sum = bitA + bitB + carry;
        result[i] = (sum % 2) + '0'; // 0 or 1
        carry = sum / 2;             // carry is 1 if sum >= 2
    }

    // If there's a carry left, wrap it around and add again
    while (carry)
    {
        char wrap[33];
        for (int i = 0; i < len - 1; i++)
            wrap[i] = '0';
        wrap[len - 1] = '1'; // wrap-around carry bit
        wrap[len] = '\0';

        char temp[33];
        strcpy(temp, result);

        carry = 0;
        for (int i = len - 1; i >= 0; i--)
        {
            int bitA = temp[i] - '0';
            int bitB = wrap[i] - '0';
            int sum = bitA + bitB + carry;
            result[i] = (sum % 2) + '0';
            carry = sum / 2;
        }
        result[len] = '\0';
    }
}

// Convert binary string to 1's complement (flip all bits)
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
    char dataword[MAX];
    int segmentLength;

    // Step 1: Input dataword and segment length
    printf("Enter the dataword (binary): ");
    scanf("%s", dataword);

    printf("Enter the segment length: ");
    scanf("%d", &segmentLength);

    int len = strlen(dataword); // total length of dataword

    // Step 2: Make sure dataword is divisible by segment length
    if (len % segmentLength != 0)
    {
        printf("Error: Data length must be divisible by segment length.\n");
        return 1;
    }

    // Step 3: Initialize sum to all 0s
    char sum[33] = {0};
    for (int i = 0; i < segmentLength; i++)
        sum[i] = '0';
    sum[segmentLength] = '\0';

    char segment[33], temp[33];

    // Step 4: Add each segment to the sum
    for (int i = 0; i < len; i += segmentLength)
    {
        // Copy each segment
        for (int j = 0; j < segmentLength; j++)
        {
            segment[j] = dataword[i + j];
        }
        segment[segmentLength] = '\0';

        // Add current segment to running sum
        addBinary(sum, segment, temp, segmentLength);
        strcpy(sum, temp); // update sum
    }

    // Step 5: Find 1's complement of sum => checksum
    onesComplement(sum, segmentLength);

    // Step 6: Output checksum and codeword
    printf("Checksum: %s\n", sum);
    printf("Code word: %s%s\n", dataword, sum); // append checksum to data

    return 0;
}
