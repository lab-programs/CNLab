#include<stdio.h>

int computePublicKey(int base, int privateKey, int prime) {
	int publicKey=1;
	
	while(privateKey > 0) {
	
		if(privateKey % 2 == 1) {
			publicKey = (publicKey*base) % prime;
		}
		
		base = base*base % prime;
		
		privateKey /= 2;
	}
	
	return publicKey;
}

int computeSecretKey(int base, int publicKey, int prime) {
	return computePublicKey(base, publicKey, prime);
}

int main() {
	int prime, base, privateKeyA, privateKeyB, publicKeyA, publicKeyB, secretKeyA, secretKeyB;
	
	printf("Enter the prime: ");
	scanf("%d", &prime);
	printf("Enter the base: ");
	scanf("%d", &base);
	printf("Enter A's Private Key: ");
	scanf("%d", &privateKeyA);
	printf("Enter B's Private Key: ");
	scanf("%d", &privateKeyB);
	
	publicKeyA = computePublicKey(base, privateKeyA, prime);
	publicKeyB = computePublicKey(base, privateKeyB, prime);
	
	secretKeyA = computeSecretKey(publicKeyB, privateKeyA, prime);
	secretKeyB = computeSecretKey(publicKeyA, privateKeyB, prime);
	
	printf("Alice Secret key is = %d\nBob's Secret Key is = %d\n", secretKeyA, secretKeyB);
	
	return 0;
}
