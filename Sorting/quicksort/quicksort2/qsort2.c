#include <stdio.h>
#include <stdlib.h>

int b[] = {66, 78, 300, 99, 88, 100, 45, 38, 12, 62, 42, 34, 8, 24, 66, 48};
int c[] = {16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
int N = 16;

int part = 0;
int swaps = 0;

// ------------------------------------------------
// Quicksort
//      Best case:  O(N*logN)
//      Worst case: O(N*N)
// ------------------------------------------------
void SWAP(int *a, int l, int r)
{
 int z = a[l]; 
 a[l] = a[r]; 
 a[r] = z;
}

// Improvement of comparison in the 2nd inner while loop checking that the "right" index does not go below 0 
// resulting in out of array boundary, which may cause unnecessary longer run time or segmentation fault. 
// By adding "&& right" check, it will ensure that the loop will stop when "right" is 0, which is an
// more efficient boolean expression (&& right) logic than adding comparison of (&& right > left).
int partition( int *a, int low, int high )
{
  int left = low-1; 
  int right = high;
  int pivot = a[high];

  
  while ( left < right ) 
  {
    while (a[++left] < pivot);
    while (a[--right] > pivot && right);

    if ( left < right ) 
    { 
       SWAP(a, left, right);
    }
  }
   
  SWAP(a, left, high);
 
  return left;
}

void quicksort(int *a, int low, int high)
{
  if (low < high)
  {
    int pivot = partition(a, low, high );
    quicksort(a, low, pivot-1);
    quicksort(a, pivot+1, high);
  }
}

int main()
{
  int i;

//  ret = __builtin_return_address(1);
 // printf("Next func address = %x \n\n", ret);

  printf("\nBefore sorting b[] = ");
  for (i=0; i<N; i++)
  {
     printf("%d ", c[i]);
  }
  printf("\n\n");

  quicksort(c, 0, N-1);

  printf("\nAfter  sorting b[] = ");
  for (i=0; i<N; i++)
  {
     printf("%d ", c[i]);
  }
  printf("\n");

  return 0;
}
