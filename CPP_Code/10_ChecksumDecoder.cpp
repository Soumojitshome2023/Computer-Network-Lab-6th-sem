/*
2. Write a C code to decode a user provided codeword using Checksum procedure.
Provide the output along with original data (good/bad).
Input:
Codeword: 1100110010101010111100001100001111010011
Segment length: 8
Output:
Data recv ok
ACTUAL data IS: 1 1 0 0 1 1 0 0 1 0 1 0 1 0 1 0 1 1 1 1 0 0 0 0 1 1 0 0 0 0 1 1
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
        int sum = (a_padded[i] - '0') + (b_padded[i] - '0') + carry;
        carry = sum / 2;
        result = char(sum % 2 + '0') + result;
    }

    // Add final carry if exists
    if (carry)
    {
        result = '1' + result;
    }

    return result;
}

// Function to verify checksum
bool verifyChecksum(const string &codeword, int segmentLength)
{
    vector<string> segments;

    // Divide codeword into segments
    for (int i = 0; i < codeword.length(); i += segmentLength)
    {
        string segment = codeword.substr(i, segmentLength);
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

    // Check if all bits are 1 (valid checksum)
    for (char bit : sum)
    {
        if (bit != '1')
            return false;
    }

    return true;
}

int main()
{
    string codeword;
    int segmentLength;

    cout << "Enter the codeword (binary string): ";
    cin >> codeword;

    cout << "Enter segment length: ";
    cin >> segmentLength;

    // Validate input
    for (char bit : codeword)
    {
        if (bit != '0' && bit != '1')
        {
            cout << "Error: Input must contain only 0s and 1s" << endl;
            return 1;
        }
    }

    // Get dataword (remove checksum)
    string dataword = codeword.substr(0, codeword.length() - segmentLength);

    // Verify checksum
    if (verifyChecksum(codeword, segmentLength))
    {
        cout << "\nData recv ok" << endl;
        cout << "ACTUAL data IS: " << dataword << endl;
    }
    else
    {
        cout << "\nData corrupted" << endl;
    }

    return 0;
}


/*
Dataword:      11001100101010101111000011000011
SegmentLength: 8

Dataword:      11001100101010101111000011000011
SegmentLength: 8

*/