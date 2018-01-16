#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int N = 17;

// input array; and the results
int A[] = {66, 78, 300, 99, 88, 100, 45, 38, 12, 62, 42, 34, 8, 24, 66, 1000, 48};

// Work array
int B[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

// -----------------------------------------------------------------
//          Prototyping functions
// -----------------------------------------------------------------
void CopyArray(int a[], int l, int r, int b[]);
int min (int x, int y);
void Merge(int A[], int begin, int middle, int end, int B[]);

void BottomUpMergeSort(int A[], int B[], int n);
void TopDownMergeSort(int A[], int begin, int end, int B[]);


// -----------------------------------------------------------------
//          Implementations of functions
// -----------------------------------------------------------------

void CopyArray(int a[], int l, int r, int b[])
{
	int k;
    for(k = l; k < r; k++)
        b[k] = a[k];
}

int min (int x, int y)
{
	return (x < y)? x:y;
}

// Left sorted half is     A[begin..middle-1]
// Right sorted half is    A[middle..end-1]
// Result is in work array B[ begin..end-1]
void Merge(int A[], int begin, int middle, int end, int B[])
{
    int i = begin; 
    int j = middle;
    int k;
	
	printf("Merge(A[], %d, %d, %d, B[])\n", begin, middle, end);
    
    // for all elements
    for (k = begin; k < end; k++) 
    {
        if ( i<middle && (j>=end || A[i] <= A[j])) 
		{
            B[k] = A[i++];
        } 
		else 
		{
            B[k] = A[j++];
        }
    } 
	
    CopyArray(B, begin, end, A);
}


void TopDownMergeSort(int A[], int begin, int end, int B[])
{
    if(end - begin < 2)
        return;    // consider it sorted
	
    int middle = (begin + end) / 2;     
	
    TopDownMergeSort(A, begin,  middle, B);
    TopDownMergeSort(A, middle, end, B);
	
    Merge(A, begin, middle, end, B);
}


void BottomUpMergeSort(int A[],int B[],int n)
{
	int width;
	int i;
	
    // Make longer sorted runs of length 2, 4, 8, 16... until whole array is sorted.
    for (width = 1; width < n; width = 2 * width)
    {
        // Array A is full of runs of length width.
        for (i = 0; i < n; i = i + 2 * width)
        {
            // Merge two runs: A[i:i+width-1] and A[i+width:i+2*width-1] to B[]
            // or copy A[i:n-1] to B[] ( if(i+width >= n) )
            // BottomUpMerge(A, i, min(i+width, n), min(i+2*width, n), B);
		    Merge(A, i, min(i+width, n), min(i+2*width, n), B);
        }
        // Now work array B is full of runs of length 2*width.
        // Copy array B to array A for next iteration.
        // A more efficient implementation would swap the roles of A and B.
		
        CopyArray(B, 0, n, A);
        // Now array A is full of runs of length 2*width.
    }	
}



int main(int argc, char* argv[])
{
	int i;

	printf("\nBefore sorting A[] = ");
	for (i=0; i<N; i++)
	{
		printf("%d ", A[i]);
	}
	printf("\n");

	printf("Command name: %s \n", argv[0]);

	if (argc == 1)
	{
		TopDownMergeSort(A, 0, N, B);
		printf("\nAfter TopDown mergesort N=%d  sorting B[] = ", N);
		for (i=0; i<N; i++)
		{
		   printf("%d ", B[i]);
		}
		printf("\n");
	}
	else if ( (argc > 1) && (strcmp(argv[1],"bot") == 0) )
	{
		BottomUpMergeSort(A, B, N);
		printf("\nAfter  BottomUpMergeSort N=%d sorting B[] = ", N);
		for (i=0; i<N; i++)
		{
		   printf("%d ", B[i]);
		}
		printf("\n");
	}
	else
	{
	  printf("Usage: msort or msort top \n");
	}

	return 0;
}
