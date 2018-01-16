// =============================================================
// Preorder traversal sequence : (root, left, right)
// Inorder traversal sequence  : (left, root, right)
// Postorder traversal sequence: (left, right, root)
// =============================================================

# include <stdio.h>
# include <stdlib.h>

#define maxN 100

void sort3(int a[], int n)
{
	int t;
	printf("\n\n Sorting N= %d elements \n", n);
	
	if (a[0] > a[1])
	{
		t = a[0];
		a[0] = a[1];
		a[1] = t;
	}
	if (a[0] > a[2])
	{
		t = a[0];
		a[0] = a[2];
		a[2] = t;
	}
	if (a[1] > a[2])
	{
		t = a[1];
		a[1] = a[2];
		a[2] = t;
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
	sort3(a, n);
	
	for (i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

