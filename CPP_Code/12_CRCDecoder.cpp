/*
2. Write a C code to decode a user provided codeword using CRC procedure.
Provide the output along with original data (good/bad).
Test Case 1:
Input:
Codeword:101000110101110
Coefficients of generator polynomial:110101
Output:
Original data receive
Actual data: 1 0 1 0 0 0 1 1 0 1

Test Case 2:
Input:
Codeword: 100100001
Coefficients of generator polynomial: 1101
Output:
Original data receive
Actual data: 1 0 0 1 0 0
*/

#include <iostream>
#include <string>
using namespace std;

// Function to perform XOR operation on two strings
string xorStrings(const string &a, const string &b)
{
    string result;
    for (int i = 0; i < b.length(); i++)
    {
        result += (a[i] == b[i] ? '0' : '1');
    }
    return result;
}

// Function to perform CRC division
string performCRC(const string &dividend, const string &divisor)
{
    string temp = dividend;
    int divisorLength = divisor.length();

    // Perform division
    for (int i = 0; i <= temp.length() - divisorLength; i++)
    {
        if (temp[i] == '1')
        {
            // XOR with divisor
            string xorResult = xorStrings(temp.substr(i, divisorLength), divisor);
            // Replace the portion of temp with XOR result
            for (int j = 0; j < divisorLength; j++)
            {
                temp[i + j] = xorResult[j];
            }
        }
    }

    // Return the remainder
    return temp.substr(temp.length() - divisorLength + 1);
}

int main()
{
    string codeword, generator;

    cout << "Enter the codeword (binary string): ";
    cin >> codeword;

    cout << "Enter coefficients of generator polynomial (binary string): ";
    cin >> generator;

    // Validate input
    for (char bit : codeword)
    {
        if (bit != '0' && bit != '1')
        {
            cout << "Error: Codeword must contain only 0s and 1s" << endl;
            return 1;
        }
    }
    for (char bit : generator)
    {
        if (bit != '0' && bit != '1')
        {
            cout << "Error: Generator polynomial must contain only 0s and 1s" << endl;
            return 1;
        }
    }

    // Perform CRC division
    string remainder = performCRC(codeword, generator);

    // Check if remainder is all zeros
    bool isValid = true;
    for (char bit : remainder)
    {
        if (bit != '0')
        {
            isValid = false;
            break;
        }
    }

    // Get original dataword by removing CRC bits
    string dataword = codeword.substr(0, codeword.length() - (generator.length() - 1));

    if (isValid)
    {
        cout << "\nOriginal data receive" << endl;
        cout << "Actual data: " << dataword << endl;
    }
    else
    {
        cout << "\nData corrupted" << endl;
    }

    return 0;
}