/*
Input a string of 0 and 1. In that string-
a. Count number of 1’s present in every alternate position starting from 1st position.
(e.g. positions 1,3,5,7,9 and so on)
b. Count number of 1’s present in every two alternate positions starting from 2nd position.
(e.g. positions 2,3,6,7,10,11,14,15 and so on)
c. Count number of 1’s present in every four alternate positions starting from 4th position.
(e.g. positions 4,5,6,7,12,13,14,15,20,21,22,23 and so on)
*/

// General function to count number of '1's in blocks of size blockSize, starting from startPos (1-based)
#include <iostream>
#include <string>
using namespace std;

int countOnesInPattern(const string &str, int blockSize)
{
    int count = 0;
    int n = str.length();
    // // Convert startPos to 0-based index
    int i = blockSize;
    while (i < n)
    {
        //     // Count '1's in the current block
        for (int j = i; j < i + blockSize; j++)
        {
            if (str[j] == '1')
            {
                count++;
            }
        }
        i += 2 * blockSize;
    }
    return count;
}

int main()
{
    string input;
    cout << "Enter binary string: ";
    cin >> input;

    // a. positions 1,3,5,... (every alternate position starting from 1st)
    int count1 = countOnesInPattern(input, 1);
    cout << "Count of 1's in positions 1,3,5,...: " << count1 << endl;

    // b. positions 2,3,6,7,10,11,... (blocks of 2 starting from 2nd, every 4 positions)
    int count2 = countOnesInPattern(input, 2);
    cout << "Count of 1's in positions 2,3,6,7,10,11,14,15,...: " << count2 << endl;

    // c. positions 4,5,6,7,12,13,14,15,... (blocks of 4 starting from 4th, every 8 positions)
    int count3 = countOnesInPattern(input, 4);
    cout << "Count of 1's in positions 4,5,6,7,12,13,14,15,20,21,22,23,...: " << count3 << endl;

    return 0;
}