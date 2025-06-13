/*
2. Write a C code to decode a user provided codeword using Even and Odd Parity bit procedure. Provide
the output along with original data (good/bad).
[Take codeword and choice of user (even parity/odd parity) as input – if the codeword and the choice
both are same (say codeword is in even parity and user choice is also even) output will be “accepted” and
print the original dataword. Otherwise output will be “Rejected / wrong codeword received”]

*/

#include <iostream>
#include <string>
using namespace std;

// Function to check if the codeword matches the expected parity
bool checkParity(const string& codeword, bool isEven) {
    int count = 0;
    for(char bit : codeword) {
        if(bit == '1') count++;
    }
    
    // For even parity: total count should be even
    // For odd parity: total count should be odd
    return (isEven ? (count % 2 == 0) : (count % 2 == 1));
}

int main() {
    string codeword;
    char choice;
    
    cout << "Enter the codeword (binary string): ";
    cin >> codeword;
    
    cout << "Enter parity type (E for Even, O for Odd): ";
    cin >> choice;
    
    // Validate input
    for(char bit : codeword) {
        if(bit != '0' && bit != '1') {
            cout << "Error: Codeword must contain only 0s and 1s" << endl;
            return 1;
        }
    }
    
    if(choice != 'E' && choice != 'O' && choice != 'e' && choice != 'o') {
        cout << "Error: Invalid parity choice. Use E for Even or O for Odd" << endl;
        return 1;
    }
    
    bool isEven = (choice == 'E' || choice == 'e');
    
    // Check parity and get dataword (remove last bit)
    string dataword = codeword.substr(0, codeword.length() - 1);
    
    if(checkParity(codeword, isEven)) {
        cout << "\nStatus: Accepted" << endl;
        cout << "Original dataword: " << dataword << endl;
    } else {
        cout << "\nStatus: Rejected / wrong codeword received" << endl;
    }
    
    return 0;
} 