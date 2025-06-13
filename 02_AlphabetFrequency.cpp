/*
2. Input a string of alphabets. Now count frequency of each alphabet present in that string.
*/

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
    string str;
    cout << "Enter a string of alphabets: ";
    getline(cin, str);
    
    int frequency[26] = {0}; // Array to store frequency of each alphabet
    
    // Count frequency of each alphabet
    for(char c : str) {
        if(isalpha(c)) {
            // Convert to lowercase and count
            frequency[tolower(c) - 'a']++;
        }
    }
    
    // Display frequency of each alphabet
    cout << "\nFrequency of each alphabet:" << endl;
    for(int i = 0; i < 26; i++) {
        if(frequency[i] > 0) {
            cout << (char)(i + 'a') << ": " << frequency[i] << endl;
        }
    }
    
    return 0;
} 