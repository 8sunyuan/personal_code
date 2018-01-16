#include "heap.h"

// Heap class has its internal array. The following array is only used for input
// where A[0] is used as one of the input elements.
int A[] = {66, 78, 300, 99, 88, 100, 45, 38, 12, 62, 42, 34, 8, 24, 66, 48};
int N = 16;



// ------------------------------------------------
// 
//            Testing Case
//
// ------------------------------------------------
// void Heapsort(int a[], int n);

void Heapsort(int a[], int n, Heap *myHeap)
{
   int i;
   for (i=0; i<n; i++)
	   myHeap->Insert(a[i]);
 
   for (i=n-1; i>=0; i--) 
        a[i] = myHeap->Remove(); 
}


int main()
{
   int i = 0;
   int v = 0;
   Heap *myHeap = NULL;
   myHeap = new Heap;
   
   // Test Case 1: Remove node from empty heap
   // ----------------------------------------
   v = myHeap->Remove();
   printf("Empty Heap Root: v = %d\n", v);
   
   // Test Case 2:  add 3 nodes, remove 2 nodes, add one; then remove all
   // -------------------------------------------------------------------
   myHeap->Insert(1000);
   myHeap->Insert(666);
   myHeap->Insert(333);
   
   v = myHeap->Remove();
   printf("Heap Root Removed: v = %d ", v);
   v = myHeap->Remove();
   printf("Heap Root Removed: v = %d\n", v);
   
   myHeap->Insert(555);
   
   v = myHeap->Remove();
   printf("Heap Root Removed: v = %d ", v);
   v = myHeap->Remove();
   printf("Heap Root Removed: v = %d\n", v);
   
   // Test Case 3: sorting 16 elements
   // --------------------------------
   printf("\nBefore sorting A[] = ");
   for (i=0; i<N; i++) printf("%d ", A[i]);
   {
		printf("\n"); 
   }
   Heapsort(&A[0], N, myHeap);
   
   printf("After Heap C++ sorting A[] = ");
   for (i=0; i<N; i++) printf("%d ", A[i]);
   printf("\n\n");
   
   return 0;    
}
