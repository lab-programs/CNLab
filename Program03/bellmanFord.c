#include<stdio.h>

struct node {
    unsigned distance[20];
    unsigned fromNode[20];
};

int main() {
    struct node nodes[10];
    
    int cost[20][20] = {{0}};
    int noOfNodes, count = 0;
    
    printf("Enter the number of nodes: ");
    scanf("%d", &noOfNodes);
    
    printf("Enter the cost matrix: \n");
    
    for(int i=1; i<=noOfNodes; i++) {
        for(int j=1; j<=noOfNodes; j++) {
            scanf("%d", &cost[i][j]);
            nodes[i].distance[j] = cost[i][j];
            nodes[i].fromNode[j] = j;
        }
    }
    
    // Repeat until no change happens to the nodes[i].distance[j]
    do {
        count=0;
        
        for(int i=1; i<=noOfNodes; i++) {
            for(int j=1; j<=noOfNodes; j++) {
                for(int k=1; k<=noOfNodes; k++) {
                    
                    // if minimum distance between i & j is greater than the sum of
                    // the cost between i & k and minimum distance b/w k & j
                    if(nodes[i].distance[j] > cost[i][k] + nodes[k].distance[j]) {
                        
                        // new minimum distance becomes this
                        nodes[i].distance[j] = nodes[i].distance[k] + nodes[k].distance[j];
                        
                        // the intermediate node is k
                        nodes[i].fromNode[j] = k;
                        
                        // increment count to indicate increment
                        count++;
                    }
                }
            }
        }
        
    } while(count != 0);
    
    for(int i=1; i<=noOfNodes; i++) {
        printf("For router %d:\n", i);
        for(int j=1; j<=noOfNodes; j++) {
            printf("\tNode %d via %d Distance %d\n", j, nodes[i].fromNode[j], nodes[i].distance[j]);
        }
    }
    
}
