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
} *vertices[MAX], *MST[MAX];

void insert(int i, int id, int cost, struct Node **list) {
    struct Node *x = (struct Node *) malloc(sizeof(struct Node));
    x->id = id;
    x->cost = cost;
    x->next = list[i];
    list[i] = x;
}

void printall(int n, struct Node **list) {
	struct Node *p;
	for(int i = 0; i < n; i++) {
        printf("\nNode %d:", i);
        p = list[i];
        while(p) {
            printf(" %d", p->id);
            p = p->next;
        }
    }
    for(int i = 0; i < n; i++) {
        printf("\nNode Costs %d:", i);
        p = list[i];
        while(p) {
            printf(" %d", p->cost);
            p = p->next;
        }
    }
}

struct HeapNode {
    int node1;
    int node2;
    //Index doesn't work as intended, only has initial inserted index
    unsigned int index;
    unsigned int priority;
} *Heap[MAX];

int size = 0;

void heapInsert(int node1, int node2, int priority) {
    int i = size++;
    // Insert node into Heap
    struct HeapNode *x = (struct HeapNode*) malloc(sizeof(struct HeapNode));
    x->node1 = node1;
    x->node2 = node2;
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
}

void heapInsertAdj(int node) {
    struct Node *p;
    for (p = vertices[node]; p; p = p->next)
        heapInsert(node, p->id, p->cost);
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


void prim(int n,int root)
{
    // pred[] stores the predecessor or parent of each node,
    // which is the final solution of the shortest-path tree.
    int pred[MAX];

    // Dijkstra algorithm assumes that the graph has non-negative cost on every edge.
    unsigned int minDistance;
    struct HeapNode *pointers[MAX];

    int visited[MAX];
    int count;
    int nextNode;
    int i,j, invalid;
    struct HeapNode *q;
    struct Node *p;

    for (i = 0; i < MAX; i++)
        Heap[i] = NULL;

    // initialize pred[],distance[] and visited[]
    for (i = 0; i < n; i++) {
        visited[i] = 0;
        pred[i] = root;
    }

    heapInsertAdj(root);
    pred[root] = root;
    visited[root] = 1;
    count = 0;

    while(count < n-1)
    {
        minDistance = INFINITY;

        // select the nextNode that has the minimum distance to the root.
        do {
            q = extractMin();
            invalid = 0;
            // Both Nodes visited, this creates cycle
            if (visited[q->node1] && visited[q->node2]) {
                invalid = 1;
            } else if (visited[q->node1]) {// Node1 is visited and in the MST, add node2's edges to heap
                heapInsertAdj(q->node2);
                pred[q->node2] = q->node1;
            } else {                       // Node2 is visited and in the MST, add node1's edges to heap
                heapInsertAdj(q->node1);
                pred[q->node1] = q->node2;
            }
        } while (invalid); // extractMin until edge doesn't create cycle

        visited[q->node1] = 1;
        visited[q->node2] = 1;

        // Add q edge to MST
        insert(q->node1, q->node2, q->priority, MST);
        insert(q->node2, q->node1, q->priority, MST);

        count++;
    }
    //print the shortest-path tree: the path and distance of each node to the root
    for(i = 0; i < n; i++)
    {
        printf("\nNode %d:", i);
        for (p = MST[i]; p; p = p->next)
            printf(" %d", p->id);
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
            if (weight) insert(i, j, weight, vertices);
        }
    }
    printf("\nEnter the starting root node:");
    scanf("%d",&u);
    prim(n,u);

    end_t = clock();
    time_t = (double)(end_t - start_t);
    printf("\n\nCPU finished in %ld\n", time_t);
    return 0;
}
