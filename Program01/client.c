// Import the Standard IO C Library
#include<stdio.h>
// Import the Standard Lib Library
#include<stdlib.h>
// Import the Unistd Library for symbolic constants
#include<unistd.h>
// Import the fcntl library for file control
#include<fcntl.h>
// Import the sys/types.h for the types needed for the program
#include<sys/types.h>
// Import sys/stat.h for defining the structure returned by some functions
#include<sys/stat.h>
// Import sys/socket.h to create and use a socket
#include<sys/socket.h>
// Import netinet/in.h for network related variables and functions
#include<netinet/in.h>
// Import arpa/inet.h for inet_pton()
#include<arpa/inet.h>

int main(int argc, char **argv) {
	// Define variables socketValue to hold the return value from the socket function
	// and n for ??
	int socketValue, n;
	
	// Define the maximum buffer size
	int bufferSize = 1024;
	
	// Allocate the buffer
	char* buffer = malloc(bufferSize);
	
	// Define the File name
	char fileName[255];
	
	// Define the socket address using the structure sockaddr_in
	struct sockaddr_in socketAddress;
	
	// Assign the sin_family and sin_port
	// sin_family = AF_INET - IPv4
	// sin_family = AF_INET6 - IPv6
	// sin_port can be any registered or dynamic port number < 65536
	socketAddress.sin_family = AF_INET;
	socketAddress.sin_port = htons(15000);
	
	// inet_pton is used to assign the IP address given in the command line argument argv[1]
	// to socketAddress
	inet_pton(AF_INET, argv[1], &socketAddress.sin_addr);
	
	// Create a tcp socket
	socketValue = socket(AF_INET, SOCK_STREAM, 0);
	
	// Connect the socket with the socketAddress
	connect(socketValue, (struct sockaddr *)&socketAddress, sizeof(socketAddress));
	
	// Request the client for the file name
	printf("\nEnter file name: ");
	scanf("%s", fileName);
	
	// Send the file name to the server
	send(socketValue, fileName, 255, 0);
	
	// Receive from the server
	while((recv(socketValue, buffer, bufferSize, 0)) > 0) {
		printf("%s", buffer);
	}
	
	// Specify EOF
	printf("\nEOF\n");
	
	// Close the socket
	return close(socketValue);
	
}
