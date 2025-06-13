/*
2. Input a string of alphabets. Now count frequency of each alphabet present in that string.
*/

#include <stdio.h>

int main()
{
    char str[1000];
    int frequency[26] = {0}; // Array to store frequency of each alphabet
    int i;

    printf("Enter a string of alphabets: ");
    scanf("%s", str); // Read a single word (no spaces)

    // Count frequency of each alphabet
    for (i = 0; str[i] != '\0'; i++)
    {
        char c = str[i];

        // Check if alphabet and convert to lowercase manually
        if (c >= 'A' && c <= 'Z')
        {
            c = c + 32; // convert to lowercase
        }

        if (c >= 'a' && c <= 'z')
        {
            frequency[c - 'a']++;
        }
    }

    // Display frequency of each alphabet
    printf("\nFrequency of each alphabet:\n");
    for (i = 0; i < 26; i++)
    {
        if (frequency[i] > 0)
        {
            printf("%c: %d\n", i + 'a', frequency[i]);
        }
    }

    return 0;
}
