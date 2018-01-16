#include <stdio.h>
#include <stdlib.h>

int b[] = {66, 78, 300, 99, 88, 100, 45, 38, 12, 62, 42, 34, 8, 24, 66, 48};
int N = 16;

int part = 0;
int swaps = 0;

void SWAP(int *a, int l, int r)
{
 int z = a[l]; 
 a[l] = a[r]; 
 a[r] = z;
}

int partition( int *a, int low, int high )
{
  int left = low-1; 
  int right = high;
  int pivot = a[high];
  int i = 0;
  part++;

  while ( left < right ) 
  {
    while (a[++left] < pivot);
    while (a[--right] > pivot);

    if ( left < right ) 
    { 
       SWAP(a, left, right);
       swaps++;
    }
  }
   
  SWAP(a, left, high);
  swaps++;

  printf("Partion = %d, Pivot = %d, Swaps = %d List = ", part, a[left], swaps);
  for (i = low; i <= high; i++)
  {
     printf("%d ", a[i]);
  }
  printf("\n");

  return left;
}

void quicksort(int *a, int low, int high)
{
  if (high > low)
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
     printf("%d ", b[i]);
  }
  printf("\n\n");

  quicksort(b, 0, N-1);

  printf("\nAfter  sorting b[] = ");
  for (i=0; i<N; i++)
  {
     printf("%d ", b[i]);
  }
  printf("\n");

  return 0;
}
