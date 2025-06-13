/*
1. Check whether a number is power of 2 or not.

*/

#include <stdio.h>

// Function to check if a number is power of 2
int isPowerOfTwo(int n)
{
    // A number is a power of 2 if it is greater than 0 and has only one bit set
    return n > 0 && (n & (n - 1)) == 0;
}

int main()
{
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    if (isPowerOfTwo(num))
    {
        printf("%d is a power of 2\n", num);
    }
    else
    {
        printf("%d is not a power of 2\n", num);
    }

    return 0;
}
