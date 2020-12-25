#include<stdio.h>
#include<stdlib.h>
#define MAX 5

int pq[MAX], f=-1, r=-1;

int isEmpty() {
    
}

void enqueue() {
    if(r >= n-1) {
        print("Overflow!\n");
    }
    else {
        if(f == -1) {
            f = 0;
        }
        int value;
        printf("Enter an element: ");
        scanf("%d", &value);
        printf("%d inserted\n", value);
        
        // Iterate from f to r-1
        for(int i=f; i<r; i++) {
            // When you find the correct priority
            if(pq[i] > item) {
                // 
                for(int j=r-1; j>= i; j--) {
                    pq[i+1] = pq[i];
                }
                pq[i] = item;
                return;
            }
        }
    }
}
