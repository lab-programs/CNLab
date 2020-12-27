#include<stdio.h>
#include<stdlib.h>
#define MAX 5

int pq[MAX+1], f=-1, r=-1;


void enqueue() {
    if(r >= MAX-1) {
        printf("Overflow!\n");
    }
    else {
        if(f == -1) {
            f = 0;
        }
        r++;
        int value;
        printf("Enter an element: ");
        scanf("%d", &value);
        printf("%d inserted\n", value);
        
        // Iterate from f to r-1
        for(int i=f; i<r; i++) {
            // When you find the correct priority
            if(pq[i] > value) {
                //
                for(int j=r-1; j>= i; j--) {
                    pq[j+1] = pq[j];
                }
                pq[i] = value;
                return;
            }
        }
        pq[r] = value;
    }
}

void dequeue() {
    if(f == -1 || r == -1) {
        r = -1;
        f = -1;
        printf("Underflow\n");
        return;
    }
    printf("%d deleted\n", pq[f]);
    for(int i=f; i<=r; i++) {
        pq[i] = pq[i+1];
    }
    r--;
}

void display() {
    if(f != -1 && r != -1) {
        printf("Priority Queue: ");
        for(int i=f; i<=r; i++) {
            printf("%d ", pq[i]);
        }
        printf("\n");
        return;
    }
    printf("Underflow\n");
}

int main() {
    int ch;
    printf("1. Enqueue   2. Dequeue   3. Display   4. Exit\n");
    do {
        printf("Enter: ");
        scanf("%d", &ch);
        switch(ch) {
            case 1: enqueue();
                break;
            case 2: dequeue();
                break;
            case 3: display();
                break;
            case 4: printf("Terminated...\n");
                break;
            default: printf("Invalid choice\n");
        }
    } while(ch != 4);
}
