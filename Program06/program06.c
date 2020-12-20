#include<stdio.h>
#include<string.h>

int checksum(int fl) {
	char inputString[100];
	int buffer[25];
	int sum=0, halfLength, temp;
	
	printf("Enter the string: ");
	scanf("%s", inputString);
	
	int len = strlen(inputString);
	if(len%2 != 0) {
		halfLength=(len+1) / 2;
	}
	else {
		halfLength=len/2;
	}
	
	for(int i=0; i<halfLength; i++) {
		int temp=inputString[i*2];
		temp=(temp*256) + inputString[(i*2)+1];
		sum += temp;
	}
	
	if(fl == 1) {
		printf("Enter the checksum value: ");
		scanf("%d", &temp);
		sum += temp;
	}
	
	if(sum%65536 != 0) {
		int modulo=sum%65536;
		sum=sum/65536+modulo;
	}
	
	int checksum=65535-sum;
	return checksum;
}

int main() {
	int choice, sum;
	
	do {
		printf("1. Encode\n2. Decode\n3. Exit\nEnter your choice: ");
		scanf("%d", &choice);
		
		switch(choice) {
			case 1: sum=checksum(0);
					printf("Checksum to append is: %d\n", sum);
					break;
			case 2:	sum=checksum(1);
					if(sum != 0) {
						printf("The data has been tampered with or invalid checksum\n");
					}
					else {
						printf("The checksum is valid\n");
					}
					break;
			case 3:
					break;
			default: printf("Invalid option, try again!\n");
		}
	} while(choice != 3);
}
