#include <stdio.h>
#include <string.h>

int cal_parity(const char *data, int parity_type)
{
	int parity = 0;
	for (int i = 0; data[i] != '\0'; i++)
	{
		if (data[i] == '1')
		{
			parity++;
		}
	}
	return (parity_type == 1) ? ((parity % 2 == 0) ? 1 : 0) : ((parity % 2 == 0) ? 0 : 1);
}

void transmit_data(const char *data, int parity_type, char *transmitted_data)
{
	int parity_bit = cal_parity(data, parity_type);
	strcpy(transmitted_data, data);
	char parity_char[2] = {parity_bit + '0', '\0'};
	strcat(transmitted_data, parity_char);
}

void reveive_data(const char *received_data, int parity_type)
{
	char data[100];
	strncpy(data, received_data, strlen(received_data) - 1);
	data[strlen(received_data) - 1] = '\0';
	int received_parity = received_data[strlen(received_data) - 1] - '0';
	int calculated_parity = cal_parity(data, parity_type);

	printf("Received Data : %s\n", data);
	if (received_parity == calculated_parity)
	{
		printf("Parity Check Passed");
	}
	else
	{
		printf("Parity Check Failed");
	}
}

int main()
{
	char data[100], transmitted_data[100];
	int parity_type;
	printf("Enter Data : ");
	scanf("%s", &data);
	printf("Enter type 0 for even 1 for odd : ");
	scanf("%d", &parity_type);
	printf("Input Data : %s\n", data);

	transmit_data(data, parity_type, transmitted_data);
	printf("Transmitted Data : %s\n", transmitted_data);
	reveive_data(transmitted_data, parity_type);
	return 0;
}
