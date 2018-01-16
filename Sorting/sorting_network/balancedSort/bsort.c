#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int N = 32;
int A[] = {66, 78, 300, 99, 88, 100, 45, 38, 12, 62, 42, 34, 8, 24, 66, 48,32, 45,34,67,32,11,30, 40,88,91,27,36,33,42,95,55};

// --------------------------------------------------------------------------
//
//  Balanced Sorting Algorithm: 
//     This is quite similar to Bitonic Sorting, but it is simpler.
//     - Worst case:   O(N*logN*logN) 
//     - Good for sorting machines (sorting network or parallel sorting)
//
// --------------------------------------------------------------------------
void SWAP(int *a, int i, int j)
{
   int z = a[i]; 
   a[i] = a[j]; 
   a[j] = z;
}


// TopDown
void BalancedMergeSort(int a[], int n);
void TopDownSplitMerge(int a[], int l, int r);
void BalancedCompare(int a[], int l, int r);


void BalancedMergeSort(int a[], int n)
{
    int i;
	
    for (i=1; i<n; i=2*i)
       TopDownSplitMerge(a, 0, n-1);
}

void TopDownSplitMerge(int a[], int l, int r)
{
    BalancedCompare(a, l, r);

    if(r - l < 2) return;
	
    int middle = (r + l) / 2;     
    TopDownSplitMerge(a, l, middle);
    TopDownSplitMerge(a, middle+1, r);
}

void BalancedCompare(int a[], int l, int r)
{
    int i = l-1; 
    int j = r+1;
    
    while (++i < --j)
    {
        if (a[i] > a[j])
           SWAP(A, i, j);
    }
}

// ------------------------------------------------------------------
//   Test Application
// ------------------------------------------------------------------
int main(int argc, char* argv[])
{
  int i;

  printf("\nBefore sorting A[] = ");
  for (i=0; i<N; i++)
  {
     printf("%d ", A[i]);
  }
  printf("\n");

  BalancedMergeSort(A, N);

  printf("\nAfter sorting N=%d  A[] = ", N);
  for (i=0; i<N; i++)
  {
     printf("%d ", A[i]);
  }
  printf("\n");


  return 0;
}
