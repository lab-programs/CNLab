#include<stdio.h>

#define INF 999

void dijkstra(int noOfNodes, int sourceNode, int cost[10][10], int distance[]) {
    
    // Declare the variables intermediateNode,
    // count as a counter, isVisited to mark the visited nodes
    // and min for minimum distance between the sourceNode and intermediateNode
    int intermediateNode, count, isVisited[10], min;
    
    // For every node
    for(int i=1; i<=noOfNodes; i++) {
        
        // Set isVisited[i] = 0 since we haven't visited any nodes
        isVisited[i]=0;
        
        // Set the distance[i] i.e., distance between sourceNode to each node
        // to the corresponding row in the Cost Matrix
        distance[i] = cost[sourceNode][i];
    }
    
    // Set the counter to two, since we have visited 1 node(sourceNode) and the
    // following while loop is executed n-1 times 2,3,4,..,n
    count = 2;
    
    // Repeat the following code n-1 times using while loop
    while(count <= noOfNodes) {
        
        // Let minimum = Infinity
        min = INF;
        
        // For every node, we check is if the distance b/w j and sourceNode
        // is less than the minimum value and the node is not already visited.
        // If so, we set the minimum as the distance between jth node and sourceNode
        // and intermediateNode as jth node
        for(int j=1; j<=noOfNodes; j++) {
            if(distance[j] < min && !isVisited[j]) {
                min = distance[j];
                intermediateNode = j;
            }
        }
        
        // We say that we have visited the intermediateNode
        isVisited[intermediateNode] = 1;
        
        // Increment the Counter
        count++;
        
        // For every jth node, we check if the sum of distances between sourceNode & intermediateNode
        // and intermediateNode and the jth node is less than the distance between the jth node &
        // the sourceNode and if the jth node is not visited, then we set the distance between
        // the jth node and sourceNode as follows
        for(int j=1; j<=noOfNodes; j++) {
            if(distance[intermediateNode] + cost[intermediateNode][j] < distance[j] && ! isVisited[j]) {
                distance[j] = distance[intermediateNode] + cost[intermediateNode][j];
            }
        }
        
    }
}


// Main Function
int main() {
    int noOfNodes, sourceNode, cost[10][10], distance[10];
    
    // Take the noOfNodes as Input
    printf("Enter the number of nodes: ");
    scanf("%d", &noOfNodes);
    
    // Take the cost matrix as Input
    printf("Enter the Cost Matrix:\n");
    for(int i=1; i<=noOfNodes; i++) {
        for(int j=1; j<=noOfNodes; j++) {
            scanf("%d", &cost[i][j]);
            if(cost[i][j] == 0) {
                cost[i][j] = INF;
            }
        }
    }
    
    // Take the sourceNode as Input
    printf("Enter the source node: ");
    scanf("%d", &sourceNode);
    
    dijkstra(noOfNodes, sourceNode, cost, distance);
    
    // Print the shortest paths
    printf("Shortest path: \n");
    for(int i=1; i<=noOfNodes; i++) {
        if(i != sourceNode) {
            printf("%d -> %d, cost = %d\n", sourceNode, i, distance[i]);
        }
    }
}
