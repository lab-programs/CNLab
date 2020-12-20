#include<stdio.h>

int main() {
	int windowSize, noOfFrames, frames[50];
	
	printf("Enter window size: ");
	scanf("%d", &windowSize);
	
	printf("Enter No of frames to transmit: ");
	scanf("%d", &noOfFrames);
	
	printf("Enter %d frames: ", noOfFrames);
	for(int i=1; i<=noOfFrames; i++) {
		scanf("%d", &frames[i]);
	}
	
	printf("\nWith sliding window protocol, the frames will be sent ");
	printf("in the following manner(assuming no corruption of frames)\n");
	
	printf("After sending %d frames at each stage, the sender ", windowSize);
	printf("waits for acknowledgement sent by the receiver\n");
	
	for(int i=1; i<=noOfFrames; i++) {
		
		// If the ith frame sent is a multiple of the windowSize
		if(i % windowSize == 0) {
			// The frame will be sent to the destination and
			// acknowledgement is to be received by the sender
			
			printf("%d\n", frames[i]);
			
			printf("Acknowledgement of above frames sent is received by sender\n");
		}
		// Else no acknowledgement is expected until the sliding window is full
		else {
			printf("%d ", frames[i]);
		}
	}
	
	if(noOfFrames % windowSize != 0) {
		printf("\nAcknowledgement of the above frames sent is received by sender\n");
	}
	
	return 0;
}
