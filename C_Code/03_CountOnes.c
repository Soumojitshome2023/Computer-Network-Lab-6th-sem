/*
3. Input a string of 0 and 1. Count number of 1’s present in that string.
*/

#include <stdio.h>

int main()
{
    char str[1000];
    int count = 0, i;

    printf("Enter a binary string (0s and 1s): ");
    scanf("%s", str); // Read input string (without spaces)

    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == '1')
        {
            count++;
        }
    }

    printf("Number of 1's in the string: %d\n", count);

    return 0;
}
