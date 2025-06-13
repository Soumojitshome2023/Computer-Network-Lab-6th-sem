/*
1. Write a C code to encode a user provided dataword using Even and Odd Parity bit procedure.
[Take a bit stream as input. Find even parity bit, even parity codeword and odd parity bit, odd parity
codeword.]
*/

#include <iostream>
#include <string>
using namespace std;

// Function to calculate parity bit (0 for even, 1 for odd)
char calculateParityBit(const string &data, bool isEven)
{
    int count = 0;
    for (char bit : data)
    {
        if (bit == '1')
            count++;
    }

    // For even parity: if count is even, parity bit is 0, else 1
    // For odd parity: if count is odd, parity bit is 0, else 1
    return (isEven ? (count % 2 == 0 ? '0' : '1') : (count % 2 == 1 ? '0' : '1'));
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
            cout << "Error: Input must contain only 0s and 1s" << endl;
            return 1;
        }
    }

    // Calculate even parity
    char evenParityBit = calculateParityBit(dataword, true);
    string evenCodeword = dataword + evenParityBit;

    // Calculate odd parity
    char oddParityBit = calculateParityBit(dataword, false);
    string oddCodeword = dataword + oddParityBit;

    // Display results
    cout << "\nResults:" << endl;
    cout << "Original dataword: " << dataword << endl;
    cout << "Even parity bit: " << evenParityBit << endl;
    cout << "Even parity codeword: " << evenCodeword << endl;
    cout << "Odd parity bit: " << oddParityBit << endl;
    cout << "Odd parity codeword: " << oddCodeword << endl;

    return 0;
}