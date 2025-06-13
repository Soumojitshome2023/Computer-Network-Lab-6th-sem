/*
4. Input a string of 0 and 1.
a. Divide it into segments of equal length.
b. If the string length is not an exact multiple of segment length then use left padding with
0s.
c. Now count number of 1’s present in each segment.
Sample Input-output:
Input: 1000111010
Segment length:4
Output:
Segment 1: 0010 <Bold indicates padding with 0>
Segment 2: 0011
Segment 3: 1010
Frequency:
Segment 1: 1
Segment 2: 2
Segment 3: 2
*/

#include <stdio.h>
#include <string.h>

int countOnes(char segment[], int length)
{
    int count = 0;
    for (int i = 0; i < length; i++)
    {
        if (segment[i] == '1')
            count++;
    }
    return count;
}

int main()
{
    char input[1000];
    char paddedInput[1100]; // extra room for padding
    int segmentLength;

    printf("Enter binary string: ");
    scanf("%s", input);

    printf("Enter segment length: ");
    scanf("%d", &segmentLength);

    int originalLength = strlen(input);
    int padding = (segmentLength - (originalLength % segmentLength)) % segmentLength;
    int totalLength = padding + originalLength;

    // Add padding
    for (int i = 0; i < padding; i++)
    {
        paddedInput[i] = '0';
    }

    // Copy input to paddedInput
    for (int i = 0; i < originalLength; i++)
    {
        paddedInput[padding + i] = input[i];
    }

    paddedInput[totalLength] = '\0'; // null-terminate the string

    // Display segments
    printf("\nSegments:\n");
    for (int i = 0; i < totalLength; i += segmentLength)
    {
        printf("Segment %d: ", (i / segmentLength) + 1);
        for (int j = 0; j < segmentLength; j++)
        {
            printf("%c", paddedInput[i + j]);
        }
        printf("\n");
    }

    // Display frequency
    printf("\nFrequency:\n");
    for (int i = 0; i < totalLength; i += segmentLength)
    {
        printf("Segment %d: %d\n", (i / segmentLength) + 1, countOnes(&paddedInput[i], segmentLength));
    }

    return 0;
}
