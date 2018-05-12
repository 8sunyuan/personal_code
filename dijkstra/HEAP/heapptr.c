#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INFINITY 999999
#define MAX 20

struct HeapNode {
    int id;
    unsigned int priority;
    struct HeapNode *par, *left, *right;
} *root = NULL;

int size = 0;

struct HeapNode * heapInsert(int id, int priority) {
    int i = size++;
    // Insert node into Heap
    struct HeapNode *x = (struct HeapNode*) malloc(sizeof(struct HeapNode));
    x->id = id;
    x->priority = priority;
    
    // Heap[i] = x;
    // // Bubble up to root
    // while (i && Heap[(i-1)/2]->priority > x->priority) {
    //     // Swap Parent and Child node
    //     Heap[i] = Heap[(i-1)/2];
    //     Heap[(i-1)/2] = x;
    //     // Update index
    //     Heap[i]->index = i;
    //     x->index = (i-1)/2;
    //
    //     i = (i-1)/2;
    // }
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
                Heap[min] = p;
            } else {
                break;
            }
            i = min;
        }

    }
    return x;
}

void decreasePriority(struct HeapNode *x, int value) {
    x->priority = value;
    int i = x->index;
    struct HeapNode *p;
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
        printf(" %d,", Heap[i]->priority);
    printf(" ]\n");
}

int main(int argc, char **argv) {
    int num, i;
    struct HeapNode *p;
    struct HeapNode *pointers[MAX];

    for (i = 0; i < MAX; i++)
        Heap[i] = NULL;

    for (i = 1; i < argc; i++) {
        num = atoi(argv[i]);
        p = heapInsert(i, num);
        pointers[i-1] = p;
    }

    printHeap();

     p = extractMin();
     printf("INDEX:%d should be 0\nPriority:%d should be 1\n", p->index, p->priority);
    p = extractMin();
    printf("INDEX:%d should be 0\nPriority:%d should be 2\n", p->index, p->priority);

    printHeap();


    return 0;
}
