#include <stdio.h>
#include <string.h>

// Convert binary string to decimal integer
int binaryToDecimal(char *bin, int len)
{
    int val = 0;
    for (int i = 0; i < len; i++)
        val = val * 2 + (bin[i] - '0');
    return val;
}

// Convert decimal integer to binary string
void decimalToBinary(int val, char *bin, int len)
{
    for (int i = len - 1; i >= 0; i--)
    {
        bin[i] = (val % 2) + '0';
        val /= 2;
    }
    bin[len] = '\0';
}

// Take 1's complement of binary string
void onesComplement(char *bin, int len)
{
    for (int i = 0; i < len; i++)
        bin[i] = (bin[i] == '0') ? '1' : '0';
}

int main()
{
    char data[200], checksum[33];
    int segLen, sum = 0;

    printf("Enter binary dataword: ");
    scanf("%s", data);
    printf("Enter segment length: ");
    scanf("%d", &segLen);

    int len = strlen(data);

    // Padding with zeros if needed
    int pad = segLen - (len % segLen);
    if (pad != segLen)
    {
        for (int i = len + pad - 1; i >= pad; i--)
            data[i] = data[i - pad];
        for (int i = 0; i < pad; i++)
            data[i] = '0';
        data[len + pad] = '\0';
        len += pad;
    }

    // Add all segments
    for (int i = 0; i < len; i += segLen)
        sum += binaryToDecimal(data + i, segLen);

    // Handle carry bits
    while (sum >> segLen)
        sum = (sum & ((1 << segLen) - 1)) + (sum >> segLen);

    // Generate checksum
    decimalToBinary(sum, checksum, segLen);
    onesComplement(checksum, segLen);

    printf("Checksum: %s\n", checksum);
    printf("Code word: %s%s\n", data, checksum);
    return 0;
}
