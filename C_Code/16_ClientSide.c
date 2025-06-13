#include <stdio.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
  struct sockaddr_in client;
  int c_check;
  char buf[100];

  // Create socket
  c_check = socket(AF_INET, SOCK_STREAM, 0);

  // Setup client address structure (server details)
  client.sin_family = AF_INET;                 // IPv4
  client.sin_addr.s_addr = inet_addr(argv[1]); // Server IP address from command line
  client.sin_port = htons(atoi(argv[2]));      // Server port number from command line

  // Connect to the server
  connect(c_check, (struct sockaddr *)&client, sizeof(client));

  // Start chat loop
  do
  {
    recv(c_check, buf, 100, 0); // Receive message from server
    printf("\nCodeword received from sender is %s\n", buf);

    printf("Enter the string: ");
    scanf("%s", buf); // Read message to send

    send(c_check, buf, 100, 0); // Send message to server
  } while (strcmp(buf, "bye") != 0); // Exit if "bye" is sent

  // Close socket
  close(c_check);
  return 0;
}
