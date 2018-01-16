#include <stdio.h>
#include <stdlib.h>


// This array is the input/output array, where A[0] is not used by heap functions here.
int A[] = {0, 66, 78, 300, 99, 88, 100, 45, 38, 12, 62, 42, 34, 8, 24, 66, 48};
int N = 16;

/* the last element in the array */
static int LastIndex = 0;

void Upheap(int a[], int k);
void Downheap(int a[], int k);
void Insert(int a[], int v);
int Remove(int a[]);
void Heapsort(int a[], int n);


void Upheap(int a[], int k)
{
   int v = a[k];
   
   while ( (k/2 > 0) && (a[k/2] <= v) )
   {
      a[k] = a[k/2];
      k = k/2;  
   }

   a[k] = v;
}

void Downheap(int a[], int k)
{
   int j, v;
   v = a[k];
   
   while (k <= LastIndex/2)
   {
     j = k+k;
     if ((j<LastIndex)&&(a[j]<a[j+1])) j++;
	 
     if (v >= a[j]) break;
     a[k] = a[j];
     k = j;
   }
    
   a[k] = v;    
}

void Insert(int a[], int v)
{
   LastIndex++;
   a[LastIndex] = v;
   Upheap(a, LastIndex);    
}

int Remove(int a[])
{
   int v = a[1];
   a[1] = a[LastIndex--];
   Downheap(a, 1);
   
   return v;    
}

void Heapsort(int a[], int n)
{
   int i;
   
   for (i=1; i<=n; i++) Insert(a, a[i]);
   for (i=n; i>=1; i--) a[i] = Remove(a);   
}


int main()
{
   int i;
   
   printf("\nBefore sorting A[] = ");
   for (i=1; i<=N; i++) printf("%d ", A[i]);
   printf("\n");
   
   Heapsort(A, N);
   
   printf("After Heap C function sorting A[] = ");
   for (i=1; i<=N; i++) printf("%d ", A[i]);
   printf("\n\n");

   return 0;    
}
