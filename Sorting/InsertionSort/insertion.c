// =============================================================
// Preorder traversal sequence : (root, left, right)
// Inorder traversal sequence  : (left, root, right)
// Postorder traversal sequence: (left, right, root)
// =============================================================

# include <stdio.h>
# include <stdlib.h>

#define maxN 100

// Just like playing poker cards sorted them on the way of picking up new cards
void insertion(int a[], int n)
{
	int i;
	int j;
	int temp;
	int move = 0;
	
	printf("\nYou entered N = %d elements\n", n);
	
	for (i = 1; i < n; i++)
	{
		temp = a[i];
		
		// j is back checking the sorted poker cards in your hand
		for (j = i; j >= 1; j--)
		{
			if (a[j-1] > temp)
			{
				a[j] = a[j-1];
				move++;
			}
			else
				break;
		}
		a[j] = temp;
	}
	printf("\n\nTotal_Movement = %d\n", move);
	
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
	insertion(a, n);
	
	printf("\n\nHere is your sorted list by method of insertion sort\n\n");
	for (i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

