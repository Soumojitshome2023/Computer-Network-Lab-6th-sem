/*
1. Write a C code to encode a user provided dataword using CRC procedure.
Test Case 1:
Input:
Dataword: 100100
Coefficients of generator polynomial: 1101
Output:
Updated divident: 100100000
The codeword is: 100100001

Test Case 2:
Input:
Dataword : 1010001101
Coefficients of generator polynomial: 110101
Output:
Updated divident: 101000110100000
The codeword is: 101000110101110
*/

#include <iostream>
#include <string>
using namespace std;

// Function to perform CRC division
string performCRC(const string &dividend, const string &divisor)
{
    string temp = dividend;
    int n = divisor.length();
    for (int i = 0; i <= temp.length() - n; i++)
    {
        if (temp[i] == '1')
        {
            for (int j = 0; j < n; j++)
            {
                temp[i + j] = (temp[i + j] == divisor[j]) ? '0' : '1';
            }
        }
    }
    return temp.substr(temp.length() - n + 1);
}

int main()
{
    string dataword, generator;

    cout << "Enter the dataword (binary string): ";
    cin >> dataword;

    cout << "Enter coefficients of generator polynomial (binary string): ";
    cin >> generator;

    // Validate input
    for (char bit : dataword)
    {
        if (bit != '0' && bit != '1')
        {
            cout << "Error: Dataword must contain only 0s and 1s" << endl;
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

    // Create updated dividend by appending (generator length - 1) zeros
    string updatedDividend = dataword + string(generator.length() - 1, '0');

    // Calculate CRC
    string remainder = performCRC(updatedDividend, generator);

    // Create codeword by appending remainder to dataword
    string codeword = dataword + remainder;

    // Display results
    cout << "\nResults:" << endl;
    cout << "Updated dividend: " << updatedDividend << endl;
    cout << "remainder: " << remainder << endl;
    cout << "The codeword is: " << codeword << endl;

    return 0;
}