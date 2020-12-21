#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<time.h>

char* divide(char augumentedDataword[], char divisor[]) {
	int lenDivisor = strlen(divisor);
	int lenAugumentedDataword = strlen(augumentedDataword);
	// No of steps in the CRC Division
	int noOfIterations = lenAugumentedDataword - lenDivisor + 1;
	
	char dividend[18], remainders[18];
	
	// Copy the first lenDivisor bytes of the augumentedDataword to the
	// dividend. 
	strncpy(dividend, augumentedDataword, lenDivisor);
	dividend[lenDivisor] = '\0';
	
	//Set remainders to 0
	memset(remainders, 0, 18);
	
	
	for(int k=0; k<noOfIterations; k++) {
		
		// Index for remainders
		int a = 0;
		
		memset(remainders, 0, 18);
		
		// Division Procedure
		if(dividend[0] == divisor[0]) {
			for(int i=1; i<lenDivisor; i++) {
				remainders[a++] = (dividend[i] == divisor[i]) ? '0' : '1';
			}
			remainders[a] = '\0';
			strcpy(dividend, remainders);
		}
		else {
			strncpy(dividend, &dividend[1], strlen(dividend)-1);
			dividend[lenDivisor-1] = '\0';
		}
		
		// Setup for the next iteration
		int lenDividend = strlen(dividend);
		dividend[lenDividend] = augumentedDataword[k+lenDividend];
		dividend[lenDivisor] = '\0';
	}
	
	// Copy the dividend to the remainder
    char* remainder = (char*) malloc(18);
    
	strncpy(remainder, dividend, lenDivisor-1);
	remainder[lenDivisor-1] = '\0';
    
    return remainder;
}

char* charToBinary(char letter) {
    char* bin = (char *)malloc(9*sizeof(char));
	int asciiValue = (int)letter;
    for(int i=7; i>=0; i--) {
	
		int mod = asciiValue % 2;
		
		// char c = intValue + '0' -> c = 'intValue'
		bin[i] = mod + '0';
		
		asciiValue /= 2;
	}
	bin[8] = '\0';
    return bin;
}

char binaryToChar(char bin[]) {
	int asciiValue = 0;
	for(int i=7; i>=0; i--) {
		asciiValue += pow(2, 7-i)*(bin[i]-'0');
	}
	// It will return the char 
	return asciiValue;
}

int main() {
	char dataWord[126], augumentedDataword[1018], divisor[18], message[126];
	char codeWord[1018], receiverCodeword[1018], receiverDataword[1001];
	
	printf("Enter the message to be sent(char limit: 124): \n");
	fgets(dataWord, sizeof(dataWord), stdin);
    strcat(dataWord, "0");
	
    char* bin;
	bin = charToBinary(dataWord[0]);
	strcpy(augumentedDataword, bin);
    
	for(int j=1, n=strlen(dataWord); j<n; j++) {
		bin = charToBinary(dataWord[j]);
		strcat(augumentedDataword, bin);
	}
    
    
	
	// Concat 16 0's to the end of augumentedDataword
	strcat(augumentedDataword, "0000000000000000");
	
	printf("Enter Divisor/Generator(in decimal)\n");
	scanf("%s", divisor);
    
    
	char* remainder = divide(augumentedDataword, divisor);
	
	strcpy(codeWord, augumentedDataword);
	strcpy(&codeWord[strlen(augumentedDataword)-16], remainder);
	strcpy(receiverCodeword, codeWord);
	
	int noOfErrors;
	printf("Enter no of errors to be introduced during transmission: ");
	scanf("%d", &noOfErrors);
	
	srand(time(0));
	
	for(int j=0; j<noOfErrors; j++) {
		int k = rand()%strlen(receiverCodeword)-1;
		receiverCodeword[k] = (receiverCodeword[k] == '0') ? '1' : '0';
		printf("Error generated at %dth bit %dth character\n", k, 1+(k/8));
	}
	
	remainder = divide(receiverCodeword, divisor);
	if(noOfErrors != 0) {
		printf("Erroneous Transmission detected!\n");
	}

	strncpy(receiverDataword, receiverCodeword, strlen(receiverCodeword) - 16);
	receiverDataword[strlen(receiverCodeword)-16] = '\0';
    
	int k=0;
	for(int j=0; j<strlen(receiverDataword); j+=8) {
		strncpy(bin, &receiverDataword[j], 8);
		bin[8] = '\0';
		message[k++] = binaryToChar(bin);
	}
    
	message[k] = '\0';
	printf("Received message = %s\n\n", message);
}
	
