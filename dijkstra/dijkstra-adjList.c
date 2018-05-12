#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#define INFINITY 999999
#define MAX 10

struct Node {
    int id;
    unsigned int cost;
    struct Node *next;
} *vertices[MAX];

void insert(int i, int id, int cost) {
    struct Node *x = (struct Node *) malloc(sizeof(struct Node));
    x->id = id;
    x->cost = cost;
    x->next = vertices[i];
    vertices[i] = x;
}

void printall(int n) {
	struct Node *p;
	for(int i = 0; i < n; i++) {
        printf("\nNode %d:", i);
        p = vertices[i];
        while(p) {
            printf(" %d", p->id);
            p = p->next;
        }
    }
    for(int i = 0; i < n; i++) {
        printf("\nNode Costs %d:", i);
        p = vertices[i];
        while(p) {
            printf(" %d", p->cost);
            p = p->next;
        }
    }
}

void dijkstra(int n,int root)
{
    // pred[] stores the predecessor or parent of each node,
    // which is the final solution of the shortest-path tree.
    int pred[MAX];

    // Dijkstra algorithm assumes that the graph has non-negative cost on every edge.
    unsigned int distance[MAX];
    unsigned int minDistance;

    int visited[MAX];
    int count;
    int nextNode;
    int i,j;

    // initialize pred[],distance[] and visited[]
    for (i = 0; i < n; i++) {
        distance[i] = INFINITY;
        visited[i] = 0;
        pred[i] = root;
    }
    struct Node *p;
    for (p = vertices[root]; p; p = p->next)
        distance[p->id] = p->cost;
    distance[root] = 0;
    visited[root] = 1;
    count = 1;

    while(count < n-1)
    {
        minDistance = INFINITY;

        // select the nextNode that has the minimum distance to the root.
        // It is found by exhaustively checking un-visited nodes.

        // Replace with priority queue
        for(i = 0; i < n; i++)
        {
            if( (distance[i] < minDistance) && !visited[i])
            {
                minDistance = distance[i];
                nextNode = i;
            }
        }

        // Now, the new node to add onto the tree is decided,
        // but the position is not determined yet.
        visited[nextNode] = 1;
        // For all un-visited nodes, update their "distance" to the root through the "nextNode"
        // to see if a better path exists. Some nodes were not directly connected to the root,
        // their distances were INFINITY; now through the new node, they may have a actual value.
        for (p = vertices[nextNode]; p; p = p->next)
        {
            if(!visited[p->id])
            {
                if(minDistance + p->cost < distance[p->id])
                {
                    distance[p->id] = minDistance + p->cost;

                    // the shortest-path tree is growing with one more node
                    pred[p->id] = nextNode;
                }
            }
        }

        count++;
    }
    //print the shortest-path tree: the path and distance of each node to the root
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
    clock_t start_t, end_t, time_t;
    start_t = clock();

    int i,j,n,u, weight;
    printf("Enter no. of vertices:");
    scanf("%d",&n);
    printf("\nEnter the adjacency matrix:\n");
    for(i=0;i<n;i++) {
        vertices[i] = NULL;
    }
    for(i=0;i<n;i++) {
        for(j=0;j<n;j++) {
            scanf("%d", &weight);
            // Nonzero weight, insert into adjacency list
            if (weight) insert(i, j, weight);
        }
    }
    printf("\nEnter the starting root node:");
    scanf("%d",&u);
    dijkstra(n,u);

    end_t = clock();
    time_t = (double)(end_t - start_t);
    printf("\n\nCPU finished in %ld\n", time_t);
    return 0;
}
