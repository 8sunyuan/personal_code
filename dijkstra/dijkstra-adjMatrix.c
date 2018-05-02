#include<stdio.h>

#define INFINITY 999999
#define MAX 10
 
void dijkstra(int G[MAX][MAX],int n,int root)
{
    // pred[] stores the predecessor or parent of each node,
    // which is the final solution of the shortest-path tree.
    int pred[MAX];
    
    // Dijkstra algorithm assumes that the graph has non-negative cost on every edge.
    unsigned int cost[MAX][MAX],distance[MAX];
    
    int visited[MAX];
    int count;
    int minDistance;
    int nextNode;
    int i,j;
    
    // create the cost matrix
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            if(G[i][j]== 0)
                cost[i][j] = INFINITY;
            else
                cost[i][j] = G[i][j];
    
    // initialize pred[],distance[] and visited[]
    for(i=0;i<n;i++)
    {
        distance[i] = cost[root][i];
        pred[i] = root;
        visited[i] = 0;
    }
    distance[root] = 0;
    visited[root] = 1;
    count = 1;
    
    // count gives the number of nodes seen so far
    while(count < n-1)
    {
        minDistance = INFINITY;
        
        // select the nextNode that has the minimum distance to the root.
        // It is found by exhaustively checking un-visited nodes.
        for(i = 0; i < n; i++)
        {
            if( (distance[i] < minDistance) && !visited[i])
            {
                minDistance = distance[i];
                nextNode = i;
            }
        }
        
        // Now, the shortest-path tree is growing with one more node
        visited[nextNode] = 1;
                    
        // For all un-visited nodes, update their "distance" to the root through the "nextNode"
        // to see if a better path exists. Some nodes were not directly connected to the root,
        // their distances were INFINITY; now through the new node, they may have a actual value.
        for(i = 0; i < n; i++)
        {
            if(!visited[i])
            {
                if(minDistance+cost[nextNode][i] < distance[i])
                {
                    distance[i] = minDistance+cost[nextNode][i];
                    pred[i] = nextNode;
                }
            }
        }
        
        count++;
    }
 
    // print the shortest-path tree: the path and distance of each node to the root
    for(i = 0; i < n; i++)
    {
        if(i != root)
        {
            printf("\nDistance of node%d = %d",i,distance[i]);
            printf("\nPath = %d",i);
            
            j = i;
            do
            {
                j = pred[j];
                printf("<-%d",j);
            }while(j!=root);
        }
    }
    printf("\n\n");
}

// The MAIN
int main()
{
    
    int G[MAX][MAX],i,j,n,u;
    printf("Enter no. of vertices:");
    scanf("%d",&n);
    printf("\nEnter the adjacency matrix:\n");
    
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&G[i][j]);
    
    printf("\nEnter the starting root node:");
    scanf("%d",&u);
    dijkstra(G,n,u);
    
    return 0;
}
