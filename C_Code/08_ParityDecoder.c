/*
2. Write a C code to decode a user provided codeword using Even and Odd Parity bit procedure. Provide
the output along with original data (good/bad).
[Take codeword and choice of user (even parity/odd parity) as input – if the codeword and the choice
both are same (say codeword is in even parity and user choice is also even) output will be “accepted” and
print the original dataword. Otherwise output will be “Rejected / wrong codeword received”]
*/

#include <stdio.h>
#include <string.h>

// Function to check parity
int checkParity(const char codeword[], int isEven)
{
    int count = 0;
    for (int i = 0; codeword[i] != '\0'; i++)
    {
        if (codeword[i] == '1')
        {
            count++;
        }
    }

    // Even parity: total count of 1s must be even
    // Odd parity: total count of 1s must be odd
    if (isEven)
    {
        return (count % 2 == 0);
    }
    else
    {
        return (count % 2 == 1);
    }
}

int main()
{
    char codeword[100];
    char choice;
    int valid = 1;

    printf("Enter the codeword (binary string): ");
    scanf("%s", codeword);

    printf("Enter parity type (E for Even, O for Odd): ");
    scanf(" %c", &choice); // Space before %c skips any leftover newline

    // Validate codeword
    for (int i = 0; codeword[i] != '\0'; i++)
    {
        if (codeword[i] != '0' && codeword[i] != '1')
        {
            printf("Error: Codeword must contain only 0s and 1s\n");
            return 1;
        }
    }

    // Validate choice
    if (choice != 'E' && choice != 'e' && choice != 'O' && choice != 'o')
    {
        printf("Error: Invalid parity choice. Use E for Even or O for Odd\n");
        return 1;
    }

    int isEven = (choice == 'E' || choice == 'e');
    int len = strlen(codeword);

    char dataword[100];
    strncpy(dataword, codeword, len - 1);
    dataword[len - 1] = '\0'; // Null-terminate the dataword

    if (checkParity(codeword, isEven))
    {
        printf("\nStatus: Accepted\n");
        printf("Original dataword: %s\n", dataword);
    }
    else
    {
        printf("\nStatus: Rejected / wrong codeword received\n");
    }

    return 0;
}
