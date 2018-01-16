// =============================================================
// Preorder traversal sequence : (root, left, right)
// Inorder traversal sequence  : (left, root, right)
// Postorder traversal sequence: (left, right, root)
// =============================================================

# include <stdio.h>
# include <stdlib.h>

#define maxN 100

// This is another version of IndexArrary-Sort
// Here, the p[i] is not given an index i of a[i];
// instead, it is given a "barcode" of a[i].
// In order to find the original value of a[], we just 
// need to "scan" the barcode. That is it.
//
// Now, what is this "barcode" ? or what is the f(n)
// that we can map this barcode to the vaule of a[i]?

// Just like playing poker cards sorted them on the way of picking up new cards
void indexarray(int a[], int* p[], int n)
{
	int i;
	int j;
	int moves;
	int* temp;
	
	printf("\nYou entered N = %d elements\n", n);
	
	// a[] array current order
	for (i = 0; i < n; i++)
	{
		p[i] = &a[i];  // this is the "barcode"! :-)
	}
	
	for (i = 1; i < n; i++)
	{
		temp = p[i];
		
		// j is back checking the sorted poker cards in your hand
		for (j = i; j >= 1; j--)
		{
			if ( *p[j-1] > *temp)  // This is "scan the barcode"
			{
				p[j] = p[j-1];
				moves++;
			}
			else
				break;
		}
		p[j] = temp;
	}
	
	printf("\n\nSorted array with %d moves\n\n", moves);
	
	return;
}

void main() 
{
	int n  = 0;
	int i = 0;
	int a[maxN];
	int *p[maxN];
	
	printf("Michael Sun: Hello World! Please enter a number, then return \n\n");
	// get the input integers into array a[]
	while (scanf("%d", &a[n]) != EOF)
	{
		printf("Please enter another number or end with ctrl-D\n");
		n++;
	}
	
	// sort the arrary a[]
	indexarray(a, p, n);
	
	printf("\n\nHere is your sorted list by method of indexarray sort\n\n");
	for (i = 0; i < n; i++)
	{
		printf("%d ", *p[i]);
	}
	printf("\n");
}

