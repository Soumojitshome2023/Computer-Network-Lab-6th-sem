/*
3. Input a string of 0 and 1. Count number of 1’s present in that string.

*/

#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    cout << "Enter a binary string (0s and 1s): ";
    cin >> str;
    
    int count = 0;
    for(char c : str) {
        if(c == '1') {
            count++;
        }
    }
    
    cout << "Number of 1's in the string: " << count << endl;
    
    return 0;
} 