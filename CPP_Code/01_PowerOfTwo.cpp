/*
1. Check whether a number is power of 2 or not.

*/

#include <iostream>
using namespace std;

bool isPowerOfTwo(int n) {
    // A number is power of 2 if it has only one bit set
    // Using bitwise AND with (n-1) to check
    return n > 0 && (n & (n - 1)) == 0;
}

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;
    
    if (isPowerOfTwo(num)) {
        cout << num << " is a power of 2" << endl;
    } else {
        cout << num << " is not a power of 2" << endl;
    }
    
    return 0;
} 