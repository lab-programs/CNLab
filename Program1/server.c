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

int main(int argc, char **argv) {
	// Define variables socketValue to hold the return value from the socket function,
	// receivedFile for received file, newSocket for the receiving socket, n for reading file
	int socketValue, receivedFile, newSocket, n;
	
	// Define the maximum buffer size
	int bufferSize = 1024;
	
	// Allocate the buffer
	char* buffer = malloc(bufferSize);
	
	// Define the File name
	char fileName[255];
	
	// Define the socket address using the structure sockaddr_in
	struct sockaddr_in socketAddress;
	
	// Assign the sin_family and sin_port and sin_addr.s_addr
	// sin_family = AF_INET - IPv4
	// sin_family = AF_INET6 - IPv6
	// sin_port can be any registered or dynamic port number < 65536
	// INADDR_ANY means any type of s_addr
	socketAddress.sin_family = AF_INET;
	socketAddress.sin_port = htons(15000);
	socketAddress.sin_addr.s_addr = INADDR_ANY;
	
	// Create a tcp socket
	socketValue = socket(AF_INET, SOCK_STREAM, 0);
	
	// Bind the socket with the socketAddress
	bind(socketValue, (struct sockaddr *)&socketAddress, sizeof(socketAddress));
	
	// Listen for any connection requests
	listen(socketValue, 3);
	
	// New Socket to receive the file
	newSocket = accept(socketValue, (struct sockaddr *)NULL, NULL);
	
	// Receive the file from the client
	recv(newSocket, fileName, 255, 0);
	
	// Open the received file
	receivedFile = open(fileName, O_RDONLY);
	
	// Read the file
	n = read(receivedFile, buffer, bufferSize);
	
	// Send the read-only file through new socket
	send(newSocket, buffer, n, 0);
	
	// Close the new socket
	close(newSocket);
	
	// Close the socket
	return close(socketValue);
	
}
