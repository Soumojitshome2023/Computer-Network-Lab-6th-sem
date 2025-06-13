/*
Input a string of 0 and 1. In that string-
a. Count number of 1’s present in every alternate position starting from 1st position.
(e.g. positions 1,3,5,7,9 and so on)
b. Count number of 1’s present in every two alternate positions starting from 2nd position.
(e.g. positions 2,3,6,7,10,11,14,15 and so on)
c. Count number of 1’s present in every four alternate positions starting from 4th position.
(e.g. positions 4,5,6,7,12,13,14,15,20,21,22,23 and so on)
*/

#include <stdio.h>
#include <string.h>

// General function to count number of '1's in blocks of size blockSize, starting from blockSize-th position
int countOnesInPattern(char str[], int blockSize)
{
    int count = 0;
    int i = blockSize - 1; // Convert to 0-based index
    int n = strlen(str);

    while (i < n)
    {
        for (int j = i; j < i + blockSize && j < n; j++)
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
    char input[1000];

    printf("Enter binary string: ");
    scanf("%s", input);

    // a. positions 1,3,5,... (every alternate position starting from 1st)
    int count1 = countOnesInPattern(input, 1);
    printf("Count of 1's in positions 1,3,5,...: %d\n", count1);

    // b. positions 2,3,6,7,10,11,... (blocks of 2 starting from 2nd, every 4 positions)
    int count2 = countOnesInPattern(input, 2);
    printf("Count of 1's in positions 2,3,6,7,10,11,14,15,...: %d\n", count2);

    // c. positions 4,5,6,7,12,13,14,15,... (blocks of 4 starting from 4th, every 8 positions)
    int count3 = countOnesInPattern(input, 4);
    printf("Count of 1's in positions 4,5,6,7,12,13,14,15,20,21,22,23,...: %d\n", count3);

    return 0;
}
