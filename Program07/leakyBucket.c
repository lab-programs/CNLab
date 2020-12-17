#include<stdio.h>
#include<stdlib.h>

#define MIN(x, y) (x>y) ? y : x

// Main Function
int main() {
    
    // Init all variables
    // outputRate - the rate at which the packets are processed
    // droppedPacktes - no of packets dropped every second because of insufficient bucketSize
    // bucketSize - maximum no of packets that can be stored in buffer
    // extraPackets - remaining packets in the buffer after dropping (if any) every second
    // excess - amount of packets to be processed before dropping (if any) every second
    // packetsPerSecond[] - no of packets that are recieved every second
    // noOfSeconds - the no of seconds that the processor recieves the data
    // choice - to terminate the user input of packetsPerSecond
    int outputRate, droppedPackets = 0, bucketSize, extraPackets = 0, excess;
    int packetsPerSecond[10] = {0}, noOfSeconds = 0, choice;
    
    // Take Input for bucketSize
    printf("Enter Bucket Size: ");
    scanf("%d", &bucketSize);
    
    // Take Input for outputRate
    printf("Enter Output Rate: ");
    scanf("%d", &outputRate);
    
    // Repeat until choice != 0
    do {
        // Enter the packet recieved at the (noOfSeconds)th second
        printf("Enter the number of packets coming at second %d: ", noOfSeconds);
        scanf("%d", &packetsPerSecond[noOfSeconds]);
        
        // Increment noOfSeconds
        noOfSeconds++;
        
        // Termination condition
        printf("Enter 1 to continue or 0 to quit... ");
        scanf("%d", &choice);
    } while(choice);
    
    // Table
    printf(" Second \tRecieved\t  Sent  \t Dropped\tRemained\n");
    
    for(int i=0; i<noOfSeconds || extraPackets; i++) {
        // (i+1)th second
        printf("%d\t", i+1);
        printf("\t%d\t", packetsPerSecond[i]);
        printf("\t%d\t", MIN(packetsPerSecond[i] + extraPackets, outputRate));
        
        // If excess > 0
        if((excess = packetsPerSecond[i]+extraPackets-outputRate) > 0) {
            // If excess > bufferSize, there is overflow in the bucket
            // which means (excess-bucketSize) amount of packets are dropped
            // and the remaining packets remain in the bucket in extraPackets
            if(excess > bucketSize) {
                extraPackets = bucketSize;
                droppedPackets = excess-bucketSize;
            }
            // If excess <= bufferSize, the no of packets doesn't overflow.
            // Which means there won't be any packets dropped and the excess
            // will be in the bucket
            else {
                extraPackets = excess;
                droppedPackets = 0;
            }
        }
        // If excess <= 0, there is nothing in the bucket, no extra packets and no question
        // of dropping any packets
        else {
            extraPackets = 0;
            droppedPackets = 0;
        }
        
        //(i+1)th second
        printf("\t%d\t\t%d\n", droppedPackets, extraPackets);
    }
    return 0;
}
