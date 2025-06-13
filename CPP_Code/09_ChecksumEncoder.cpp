/*
1. Write a C code to encode a user provided dataword using checksum procedure.
Input:
Dataword: 11001100101010101111000011000011
Segment Length = 8
Output:
Checksum: 11010011
code word : 1100110010101010111100001100001111010011
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Function to perform binary addition of two strings
string binaryAddition(const string &a, const string &b)
{
    string result;
    int carry = 0;

    // Make both strings of equal length by padding with 0s
    int maxLen = max(a.length(), b.length());
    string a_padded = string(maxLen - a.length(), '0') + a;
    string b_padded = string(maxLen - b.length(), '0') + b;

    // Perform binary addition
    for (int i = maxLen - 1; i >= 0; i--)
    {
        // Subtracting '0' from a character digit (e.g., '1' - '0') converts it to its integer value.
        // For example, '1' - '0' = 49 - 48 = 1, and '0' - '0' = 0.
        // This allows us to perform arithmetic on the character digits.
        int sum = (a_padded[i] - '0') + (b_padded[i] - '0') + carry;
        carry = sum / 2;
        // (sum % 2) gives 0 or 1, which is a number. Adding '0' converts it to the character '0' or '1'.
        // This is necessary because result is a string of characters, not numbers.
        result = char((sum % 2) + '0') + result;
    }

    // Add final carry if exists
    if (carry)
    {
        result = '1' + result;
    }

    return result;
}

// Function to calculate checksum
string calculateChecksum(const string &dataword, int segmentLength)
{
    vector<string> segments;

    // Divide dataword into segments
    for (int i = 0; i < dataword.length(); i += segmentLength)
    {
        string segment = dataword.substr(i, segmentLength);
        // Pad with 0s if segment is incomplete
        if (segment.length() < segmentLength)
        {
            segment = string(segmentLength - segment.length(), '0') + segment;
        }
        segments.push_back(segment);
    }

    // Add all segments
    string sum = segments[0];
    for (int i = 1; i < segments.size(); i++)
    {
        sum = binaryAddition(sum, segments[i]);
    }

    // If sum length is greater than segment length, add the carry
    while (sum.length() > segmentLength)
    {
        string carry = sum.substr(0, sum.length() - segmentLength);
        sum = sum.substr(sum.length() - segmentLength);
        sum = binaryAddition(sum, carry);
    }

    // Take 1's complement of sum to get checksum
    string checksum;
    for (char bit : sum)
    {
        checksum += (bit == '0' ? '1' : '0');
    }

    return checksum;
}

int main()
{
    string dataword;
    int segmentLength;

    cout << "Enter the dataword (binary string): ";
    cin >> dataword;

    cout << "Enter segment length: ";
    cin >> segmentLength;

    // Validate input
    for (char bit : dataword)
    {
        if (bit != '0' && bit != '1')
        {
            cout << "Error: Input must contain only 0s and 1s" << endl;
            return 1;
        }
    }

    // Calculate checksum
    string checksum = calculateChecksum(dataword, segmentLength);
    string codeword = dataword + checksum;

    // Display results
    cout << "\nResults:" << endl;
    cout << "Original dataword: " << dataword << endl;
    cout << "Checksum: " << checksum << endl;
    cout << "Codeword: " << codeword << endl;

    return 0;
}