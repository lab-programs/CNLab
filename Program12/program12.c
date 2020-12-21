// RSA Algorithm for small values

#include<stdio.h>
#include<math.h>

int gcd(int a, int b) {
	if(b == 0) {
		return a;
	}
	return gcd(b, a%b);
}

int main() {
	long long prime1, prime2, productOfPrimes, phiOfProductOfPrimes, publicKey, privateKey;
	
	printf("Enter the first prime: ");
	scanf("%lld", &prime1);

	printf("Enter the second prime: ");
	scanf("%lld", &prime2);
	
	productOfPrimes = prime1 * prime2;
	
	// phi(p) = p-1 for a prime - Euler's Phi Function
	phiOfProductOfPrimes = (prime1 - 1) * (prime2 - 1);
	
	publicKey = 2;
	
	while(publicKey < phiOfProductOfPrimes) {
		if(gcd(publicKey, phiOfProductOfPrimes) == 1) {
			break;
		}
		else {
			publicKey++;
		}
	}
	
	for(int i=2; i<=productOfPrimes; i++) {
		long long expression = (publicKey*i-1) % phiOfProductOfPrimes;
		if(expression == 0) {
			privateKey = i;
			break;
		}
	}
	
	
	
	printf("Public Key: %lld\n", publicKey);
	printf("Private Key: %lld\n", privateKey);
	
	long long message;
	printf("Enter message: ");
	scanf("%lld", &message);
	
	long long encryptedMessage = powl(message, publicKey);
	encryptedMessage = encryptedMessage % productOfPrimes;
	
	long long decryptedMessage = powl(encryptedMessage, privateKey);
	decryptedMessage = decryptedMessage % productOfPrimes;
	
	printf("Original Message : %lld\n", message);
	printf("Encrypted Message: %lld\n", encryptedMessage);
	printf("Decrypted Message: %lld\n", decryptedMessage);
	
	
	return 0;
}

/**
#include<stdio.h>
#include<math.h>

int gcd(int a, int b) {
	if(b == 0) {
		return a;
	}
	return gcd(b, a%b);
}

int main() {
	long double prime1, prime2, productOfPrimes, phiOfProductOfPrimes, publicKey, privateKey;
	
	printf("Enter the first prime: ");
	scanf("%Lf", &prime1);

	printf("Enter the second prime: ");
	scanf("%Lf", &prime2);
	
	productOfPrimes = prime1 * prime2;
	
	// phi(p) = p-1 for a prime - Euler's Phi Function
	phiOfProductOfPrimes = (prime1 - 1) * (prime2 - 1);
	
	publicKey = 2;
	
	while(publicKey < phiOfProductOfPrimes) {
		if(gcd(publicKey, phiOfProductOfPrimes) == 1) {
			break;
		}
		else {
			publicKey++;
		}
	}
	
	for(int i=2; i<=productOfPrimes; i++) {
		long expression = fmodl((publicKey*i-1), phiOfProductOfPrimes);
		if(expression == 0) {
			privateKey = i;
			break;
		}
	}
	
	
	
	printf("Public Key: %Lf\n", publicKey);
	printf("Private Key: %Lf\n", privateKey);
	
	long double message;
	printf("Enter message: ");
	scanf("%Lf", &message);
	
	long double encryptedMessage = powl(message, publicKey);
	encryptedMessage = fmodl(encryptedMessage, productOfPrimes);
	
	long double decryptedMessage = powl(encryptedMessage, privateKey);
	decryptedMessage = fmodl(decryptedMessage, productOfPrimes);
	
	printf("Original Message : %Lf\n", message);
	printf("Encrypted Message: %Lf\n", encryptedMessage);
	printf("Decrypted Message: %Lf\n", decryptedMessage);
	
	
	return 0;
}
*/
