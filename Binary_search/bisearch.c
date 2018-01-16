#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// This array is the input/output array, where A[0] is not used by heap functions here.
int A[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25, 27, 29, 31, 33, 35, 37, 39, 41, 43, 45, 47, 49, 51, 53, 55, 57, 59, 61, 63};
int N = 32;

// --------------------------------------------------------
// Recursive
int binary_search(int a[], int l, int r, int key)
{
    printf("binary_search(a[], %d, %d, %d) called \n", l, r, key);
    int pos = -1;

	if (l <= r)
	{
        int mid = (l + r)/2;
        
        if (a[mid] == key)
            pos = mid;   // found it
        else if (a[mid] < key)
            pos = binary_search(a, mid+1, r, key);
        else
            pos = binary_search(a, l, mid-1, key);
	}

	return pos;
}

// --------------------------------------------------------
// Non-recursive
// Input:   a[] are sorted from small to big order
// Output:  Found: array index; Failed: -1
int bi_search(int a[], int n, int key)
{
    int l = 0;
    int r = n-1;
    
    while (l <= r) 
    {
        int mid= (l + r)/2;
        
        if (a[mid] == key)
            return mid;   // found it
        
        if (a[mid] < key)
            l = mid + 1;           
        else 
            r = mid -1;
    }
    
    // not found
    return -1; 
}

//
//
int main(int argc, char **argv)
{
	int i;
	int pos = -1;
	int key = 3;

	printf("\nSearching A[] = ");
	for (i=0; i<N; i++) printf("%d ", A[i]);
	printf("\n");

    printf("\nEnter a key to search:\n");
    while ( scanf("%d", &key) != EOF)
    {
        pos = bi_search(A, N, key);

        if (pos < 0)
        {
           printf("key = %d is not found in  A[] \n", key);
        }
        else
        {
           printf("A[%d] = key = %d match found! \n", pos, key);
        }
       
        printf("\nEnter another key to search or CTL-D to exit\n");
    }

	return 0;    
}
