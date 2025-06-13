#include <stdio.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
  char buf[100];
  struct sockaddr_in server, client;
  int s_check, c_check;

  // Create socket
  s_check = socket(AF_INET, SOCK_STREAM, 0);

  // Setup server address structure
  server.sin_family = AF_INET;            // IPv4
  server.sin_addr.s_addr = INADDR_ANY;    // Any local IP address
  server.sin_port = htons(atoi(argv[1])); // Convert port number from string to network byte order

  // Bind socket to specified IP and port
  bind(s_check, (struct sockaddr *)&server, sizeof(server));

  // Start listening for incoming connections
  listen(s_check, 1);

  // Accept a connection
  int size = sizeof(client);
  c_check = accept(s_check, (struct sockaddr *)&client, &size);

  // Start chat loop
  do
  {
    memset(buf, '\0', 100); // Clear buffer
    printf("Enter the string: ");
    scanf("%s", buf); // Read message from server user

    send(c_check, buf, 100, 0);                                         // Send message to client
    printf("\nClient IP address is: %s\n", inet_ntoa(client.sin_addr)); // Display client IP

    recv(c_check, buf, 100, 0);               // Receive message from client
    printf("\nReceived data is : %s\n", buf); // Display received message
  } while (strcmp(buf, "bye") != 0); // Exit if "bye" is received

  // Close sockets
  close(c_check);
  close(s_check);
  return 0;
}
