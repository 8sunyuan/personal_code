// =============================================================
// Preorder traversal sequence : (root, left, right)
// Inorder traversal sequence  : (left, root, right)
// Postorder traversal sequence: (left, right, root)
// =============================================================

# include <stdio.h>
# include <stdlib.h>

#define maxN 100

void selection(int a[], int n)
{
	int i;
	int j;
	int min;
	int t;
	
	for (i = 0; i < n-1; i++)
	{
		min = i;
		for (j = i+1; j <= n; j++)
		{
			if (a[j] < a[min])
			{
				min = j;
			}
		}
		
		t = a[min];
		a[min] = a[i];
		a[i] = t;
	}
	
	return;
}

void main() 
{
	int n  = 0;
	int i = 0;
	int a[maxN];
	
	printf("Michael Sun: Hello World! Please enter a number, then return \n\n");
	// get the input integers into array a[]
	while (scanf("%d", &a[n]) != EOF)
	{
		printf("Please enter another number or end with ctrl-D\n");
		n++;
	}
	
	// sort the arrary a[]
	selection(a, n);
	
	printf("\n\nHere is your sorted list by method of selection sort\n\n");
	for (i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

