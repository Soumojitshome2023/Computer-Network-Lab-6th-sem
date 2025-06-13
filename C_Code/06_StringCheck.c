/*
Question: Check whether the given input string contains
a. only alphabets
b. only digits
c. only 0s and 1s
*/

#include <stdio.h>

// Function to check if all characters are alphabets
int containsOnlyAlphabets(char str[])
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (!((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z')))
        {
            return 0;
        }
    }
    return 1;
}

// Function to check if all characters are digits
int containsOnlyDigits(char str[])
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (!(str[i] >= '0' && str[i] <= '9'))
        {
            return 0;
        }
    }
    return 1;
}

// Function to check if all characters are 0 or 1
int containsOnlyBinary(char str[])
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] != '0' && str[i] != '1')
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    char input[1000];

    printf("Enter a string: ");
    scanf("%s", input);

    printf("\nString Analysis:\n");
    printf("Contains only alphabets: %s\n", containsOnlyAlphabets(input) ? "Yes" : "No");
    printf("Contains only digits: %s\n", containsOnlyDigits(input) ? "Yes" : "No");
    printf("Contains only 0s and 1s: %s\n", containsOnlyBinary(input) ? "Yes" : "No");

    return 0;
}
