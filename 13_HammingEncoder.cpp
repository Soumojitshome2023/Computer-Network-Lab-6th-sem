/*
1. Write a C code to encode a user provided dataword using Hamming Code procedure.
Test case 1:
Input:
Dataword: 1100101
Output:
No of redundant bits: 4
The codeword is: 11000101100

Test case 2:
Input:
Dataword: 1011010
Output:
No of redundant bits: 4
The codeword is: 10101010000
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Function to calculate number of redundant bits needed
int calculateRedundantBits(int dataLength)
{
    int r = 0;
    int power = 1;
    while (power < dataLength + r + 1)
    {
        r++;
        power = 1;
        for (int i = 0; i < r; i++)
        {
            power = power * 2;
        }
    }
    return r;
}

// Function to create Hamming code
string createHammingCode(const string &dataword)
{
    int dataLength = dataword.length();
    int r = calculateRedundantBits(dataLength);
    int totalLength = dataLength + r;

    // Initialize codeword with all positions as '0'
    string codeword(totalLength, '0');

    // Place data bits in their positions (skipping positions that are powers of 2)
    int j = 0;
    for (int i = 0; i < totalLength; i++)
    {
        // We want to place data bits in positions that are NOT powers of 2,
        // because positions that ARE powers of 2 (1, 2, 4, 8, ...) are reserved for parity bits.
        // To check if a number is a power of 2, we can use the property:
        //    n is a power of 2 if (n & (n - 1)) == 0
        // Here, (i + 1) is the position (since array is 0-indexed).
        // So, (i + 1) is NOT a power of 2 if ((i + 1) & i) != 0.
        // Example:
        //   i = 2 --> (i + 1) = 3, 3 & 2 = 2 (not zero), so position 3 is NOT a power of 2 (place data bit)
        //   i = 3 --> (i + 1) = 4, 4 & 3 = 0, so position 4 IS a power of 2 (skip, it's a parity bit)
        if (((i + 1) & i) != 0)
        { // If position is not a power of 2
            codeword[i] = dataword[j++];
        }
    }

    // Calculate parity bits
    // Simple way: For each parity bit position, check all bits whose (position+1) has the parity bit set
    for (int i = 0; i < r; i++)
    {
        // 'pos' is the index (0-based) where the i-th parity bit should be placed.
        // For Hamming code, parity bits are placed at positions 1, 2, 4, 8, ... (i.e., 2^i, 1-based).
        // Since our array is 0-indexed, the position is (2^i) - 1.
        int pos = (1 << i) - 1; // Parity bit position (0-indexed)
        int count = 0;
        for (int j = 0; j < totalLength; j++)
        {
            if (((j + 1) & (1 << i)) && codeword[j] == '1')
            {
                count++;
            }
        }
        codeword[pos] = (count % 2 == 0) ? '0' : '1';
    }

    return codeword;
}

int main()
{
    string dataword;

    cout << "Enter the dataword (binary string): ";
    cin >> dataword;

    // Validate input
    for (char bit : dataword)
    {
        if (bit != '0' && bit != '1')
        {
            cout << "Error: Dataword must contain only 0s and 1s" << endl;
            return 1;
        }
    }

    // Calculate number of redundant bits
    int r = calculateRedundantBits(dataword.length());

    // Create Hamming code
    string codeword = createHammingCode(dataword);

    // Display results
    cout << "\nResults:" << endl;
    cout << "No of redundant bits: " << r << endl;
    cout << "The codeword is: " << codeword << endl;

    return 0;
}