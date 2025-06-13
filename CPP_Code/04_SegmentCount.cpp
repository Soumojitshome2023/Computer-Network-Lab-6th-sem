/*
4. Input a string of 0 and 1.
a. Divide it into segments of equal length.
b. If the string length is not an exact multiple of segment length then use left padding with
0s.
c. Now count number of 1’s present in each segment.
Sample Input-output:
Input: 1000111010
Segment length:4
Output:
Segment 1: 0010 <Bold indicates padding with 0>
Segment 2: 0011
Segment 3: 1010
Frequency:
Segment 1: 1
Segment 2: 2
Segment 3: 2
*/

#include <iostream>
#include <string>
using namespace std;

int countOnes(const string& segment) {
    int count = 0;
    for(char c : segment) {
        if(c == '1') count++;
    }
    return count;
}

int main() {
    string input;
    int segmentLength;
    
    cout << "Enter binary string: ";
    cin >> input;
    cout << "Enter segment length: ";
    cin >> segmentLength;
    
    // Calculate padding needed
    // Calculate how many zeros need to be added to the left of the input string
    // so that its length becomes a multiple of segmentLength.
    // If the input length is already a multiple, padding will be 0.
    int padding = (segmentLength - (input.length() % segmentLength)) % segmentLength;
    // Create a new string with 'padding' number of '0's, then append the original input.
    // This ensures the total length is divisible by segmentLength.
    string paddedInput = string(padding, '0') + input;
    
    // Process segments
    cout << "\nSegments:" << endl;
    for(int i = 0; i < paddedInput.length(); i += segmentLength) {
        string segment = paddedInput.substr(i, segmentLength);
        cout << "Segment " << (i/segmentLength + 1) << ": " << segment << endl;
    }
    
    // Count 1's in each segment
    cout << "\nFrequency:" << endl;
    for(int i = 0; i < paddedInput.length(); i += segmentLength) {
        string segment = paddedInput.substr(i, segmentLength);
        cout << "Segment " << (i/segmentLength + 1) << ": " << countOnes(segment) << endl;
    }
    
    return 0;
} 