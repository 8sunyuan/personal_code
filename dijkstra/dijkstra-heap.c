#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#define INFINITY 999999
#define MAX 10


struct HeapNode {
    int id;
    //Index doesn't work as intended, only has initial inserted index
    unsigned int index;
    unsigned int priority;
} *Heap[MAX];

int size = 0;

struct HeapNode * heapInsert(int id, int priority) {
    int i = size++;
    // Insert node into Heap
    struct HeapNode *x = (struct HeapNode*) malloc(sizeof(struct HeapNode));
    x->id = id;
    x->priority = priority;
    x->index = size;
    Heap[i] = x;
    // Bubble up to root
    while (i && Heap[(i-1)/2]->priority > x->priority) {
        // Swap Parent and Child node
        Heap[i] = Heap[(i-1)/2];
        Heap[(i-1)/2] = x;
        // Update index
        Heap[i]->index = i;
        x->index = (i-1)/2;

        i = (i-1)/2;
    }
    return x;
}

struct HeapNode * extractMin() {
    // Size == 0 means empty heap
    struct HeapNode *p, *x = NULL;
    int left, right, min, i;
    // if nonempty
    if (size) {
        // Replace root with bottom node
        x = Heap[0];
        Heap[0] = Heap[--size];
        // Bubble down new root node
        i = 0;
        while(i < size) {
            min = i;
            left = 2*i + 1;
            right = 2*i + 2;
            if (left < size && Heap[left]->priority < Heap[min]->priority)
                min = left;
            if (right < size && Heap[right]->priority < Heap[min]->priority)
                min = right;
            if (min != i) {
                p = Heap[i];
                Heap[i] = Heap[min];
                Heap[i]->index = i;
                Heap[min] = p;
                Heap[min]->index = min;

            } else {
                break;
            }
            i = min;
        }

    }
    return x;
}

void decreasePriority(struct HeapNode *x, int value) {
    struct HeapNode *p;
    int i = x->index;
    x->priority = value;
    while (i && Heap[(i-1)/2]->priority > x->priority) {
        // Swap Parent and Child node
        p = Heap[(i-1)/2];
        Heap[i] = p;
        Heap[(i-1)/2] = x;
        // Update index
        p->index = i;
        x->index = (i-1)/2;

        i = (i-1)/2;
    }
}

void printHeap() {
    printf("  [");
    for (int i = 0; i < size; i++)
        printf(" %d: %d,", Heap[i]->index , Heap[i]->priority);
    printf(" ]\n");
}

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
    struct HeapNode *pointers[MAX];

    int visited[MAX];
    int count;
    int nextNode;
    int i,j;
    struct HeapNode *q;
    struct Node *p;

    for (i = 0; i < MAX; i++)
        Heap[i] = NULL;

    // initialize pred[],distance[] and visited[]
    for (i = 0; i < n; i++) {
        q = heapInsert(i, INFINITY);
        pointers[i] = q;
        distance[i] = INFINITY;
        visited[i] = 0;
        pred[i] = root;
    }
    for (p = vertices[root]; p; p = p->next) {
        distance[p->id] = p->cost;
        decreasePriority(pointers[p->id], p->cost);
    }
    distance[root] = 0;
    visited[root] = 1;
    count = 1;
    decreasePriority(pointers[root], 0);
    q = extractMin();

    while(count < n-1)
    {
        minDistance = INFINITY;

        // select the nextNode that has the minimum distance to the root.
        q = extractMin();
        minDistance = distance[q->id];
        nextNode = q->id;

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

                    decreasePriority(pointers[p->id], minDistance + p->cost);
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
