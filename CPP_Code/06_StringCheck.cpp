/*
Question: Check whether the given input string contains
a. only alphabets
b. only digits
c. only 0s and 1s
*/

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

bool containsOnlyAlphabets(const string& str) {
    for(char c : str) {
        if(!isalpha(c)) return false;
    }
    return true;
}

bool containsOnlyDigits(const string& str) {
    for(char c : str) {
        if(!isdigit(c)) return false;
    }
    return true;
}

bool containsOnlyBinary(const string& str) {
    for(char c : str) {
        if(c != '0' && c != '1') return false;
    }
    return true;
}

int main() {
    string input;
    cout << "Enter a string: ";
    cin >> input;
    
    cout << "\nString Analysis:" << endl;
    cout << "Contains only alphabets: " << (containsOnlyAlphabets(input) ? "Yes" : "No") << endl;
    cout << "Contains only digits: " << (containsOnlyDigits(input) ? "Yes" : "No") << endl;
    cout << "Contains only 0s and 1s: " << (containsOnlyBinary(input) ? "Yes" : "No") << endl;
    
    return 0;
} 