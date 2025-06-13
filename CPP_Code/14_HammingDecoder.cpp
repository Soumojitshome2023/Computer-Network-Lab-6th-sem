/*
Question: Write a C code to decode a user provided codeword using Hamming Code procedure.
[Input will be the generated codeword. If there is no error Output will be "Actual data received". 
If there is any error in the codeword, output will be the position of the error and the original codeword]
Test case 1:
Input:
Codeword: 10101010000
Output:
Actual data received
Test case 2:
Input:
Codeword: 10101000000
Output:
Wrong data received
Error at position 5
Corrected codeword is: 10101010000
*/

#include <iostream>
#include <string>
using namespace std;

// Function to detect and correct errors in Hamming code
pair<bool, int> detectAndCorrectError(string& codeword) {
    int r = 0;
    while((1 << r) < codeword.length()) {
        r++;
    }
    
    int errorPos = 0;
    
    // Calculate syndrome
    for(int i = 0; i < r; i++) {
        int pos = (1 << i) - 1;
        int count = 0;
        
        // Check all bits that have (i+1)th bit set in their position
        for(int j = pos; j < codeword.length(); j++) {
            if(((j + 1) & (1 << i)) && codeword[j] == '1') {
                count++;
            }
        }
        
        // If count is odd, set corresponding bit in error position
        if(count % 2 != 0) {
            errorPos |= (1 << i);
        }
    }
    
    // If error position is 0, no error
    if(errorPos == 0) {
        return {true, 0};
    }
    
    // Correct the error
    codeword[errorPos - 1] = (codeword[errorPos - 1] == '0') ? '1' : '0';
    
    return {false, errorPos};
}

int main() {
    string codeword;
    
    cout << "Enter the codeword (binary string): ";
    cin >> codeword;
    
    // Validate input
    for(char bit : codeword) {
        if(bit != '0' && bit != '1') {
            cout << "Error: Codeword must contain only 0s and 1s" << endl;
            return 1;
        }
    }
    
    // Make a copy of codeword for correction
    string originalCodeword = codeword;
    
    // Detect and correct errors
    auto [isValid, errorPos] = detectAndCorrectError(codeword);
    
    if(isValid) {
        cout << "\nActual data received" << endl;
    } else {
        cout << "\nWrong data received" << endl;
        cout << "Error at position " << errorPos << endl;
        cout << "Corrected codeword is: " << codeword << endl;
    }
    
    return 0;
} 