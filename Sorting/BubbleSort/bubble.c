// =============================================================
// Preorder traversal sequence : (root, left, right)
// Inorder traversal sequence  : (left, root, right)
// Postorder traversal sequence: (left, right, root)
// =============================================================

# include <stdio.h>
# include <stdlib.h>

#define maxN 100

void bubble(int a[], int n)
{
	int i;
	int j;
	int t;
	printf("\n\n Sorting N= %d elements \n", n);
	
	for (i = n-1; i >= 1; i--)
	{
		for (j = 1; j <= i; j++)
		{
			if 	(a[j-1] > a[j])
			{
				t = a[j-1];
				a[j-1] = a[j];
				a[j] = t;
			}
		}
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
	bubble(a, n);
	printf("\nSorted the array by bubble sort\n\n");
	
	for (i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

