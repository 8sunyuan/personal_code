#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int N = 16;
int A[] = {66, 78, 300, 99, 88, 100, 45, 38, 12, 62, 42, 34, 8, 24, 66, 48};

// ------------------------------------------------------------------------
//  
//   This Batcher's Odd-Even sorting algorithm
//       - Worst-case:  O(N**2)
//       - Similar to Bubble sort
//       - Good for sorting networks (parallel sorting)
//
// ------------------------------------------------------------------------
void OddEvenSort(int a[], int n);

void SWAP(int *a, int l, int r)
{
   int z = a[l]; 
   a[l] = a[r]; 
   a[r] = z;
}

void OddEvenSort (int a[], int n)
{
    int i;
    int j;

    for (i = 0 ; i < n ; i++)
    {
		 // check the first bit of i: Bit-wise-AND
         if (i & 1) // i is odd
         {
             for (j = 2 ; j < n ; j += 2)
             {     
                  if (a[j] < a[j-1])
                      SWAP(a, j-1, j);
             }
          }
          else // i is even
          {  
              for (j = 1 ; j < n ; j += 2)
              {
                   if (a[j] < a[j-1])
                       SWAP(a, j-1, j);
              } 
          }
    }
}


// -----------------------------------------------------------------------
int main(int argc, char* argv[])
{
  int i;

  printf("\nBefore sorting A[] = ");
  for (i=0; i<N; i++)
  {
     printf("%d ", A[i]);
  }
  printf("\n");

  OddEvenSort(A, N);

  printf("\nAfter Odd-Even sorting  A[] = ");
  for (i=0; i<N; i++)
  {
     printf("%d ", A[i]);
  }
  printf("\n");


  return 0;
}
