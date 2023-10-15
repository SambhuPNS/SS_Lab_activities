#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define SERVER_IP "127.0.0.1" // IP address of the server (change as needed)
#define SERVER_PORT 8080
#define MAX_BUFFER_SIZE 1024

int main() 

{
    int client_socket;
    struct sockaddr_in server_addr;
    char buffer[MAX_BUFFER_SIZE];

    // Create socket
    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket < 0) 
    {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if (inet_pton(AF_INET, SERVER_IP, &server_addr.sin_addr) <= 0) 
    {
        perror("Invalid address/Address not supported");
        exit(EXIT_FAILURE);
    }

    // Connect to the server
    if (connect(client_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) 
    {
        perror("Connection failed");
        exit(EXIT_FAILURE);
    }

    // Send a message to the server
    const char *message = "Hello from client!";
    send(client_socket, message, strlen(message), 0);
    printf("Message sent to server: %s\n", message);

    // Receive a response from the server
    int bytes_received = read(client_socket, buffer, sizeof(buffer));
    if (bytes_received < 0) 
    {
        perror("Read failed");
        exit(EXIT_FAILURE);
    }

    buffer[bytes_received] = '\0'; // Null-terminate the received data
    printf("Server response: %s\n", buffer);

    // Close the socket
    close(client_socket);

    return 0;
}

