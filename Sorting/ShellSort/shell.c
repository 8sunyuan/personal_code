// =============================================================
// Preorder traversal sequence : (root, left, right)
// Inorder traversal sequence  : (left, root, right)
// Postorder traversal sequence: (left, right, root)
// =============================================================

# include <stdio.h>
# include <stdlib.h>

#define maxN 100


int init(int n)
{
	int h;
	for (h=0; h<=n/9; h=3*h+1)
	{}

    return h;
}
// Insertion-sort is in fact shell-sort with h=1 only.
// Shell-sort takes, for example, a sequnce of h = 3*h + 1, and h <= n/9
// which is from prof. Knuth of Stanford.
//
const int M = 5;
int H[] = {17, 11, 7, 3, 1};

void shell(int a[], int n)
{
	int i;
	int j;
	int h;
	int m;
	int temp;
	int move = 0;
	int total = 0;
	
	printf("\nYou entered N = %d elements\n", n);
	
	// for (h=init(n); h > 0; h = h/3)
    for (m = 0; m < M; m++)
	{
		h = H[m];
		
		move = 0;
		for (i = h; i < n; i++)
		{
			temp = a[i];
			
			// j is back checking the sorted poker cards in your hand
			for (j = i; j >= h; j=j-h)
			{
				if (a[j-h] > temp)
				{
					a[j] = a[j-h];
					move++;
				}
				else
					break;
			}
			a[j] = temp;
		}
		printf("\n\n Movements = %d for h = %d \n\n", move, h);
		total = total + move;
	}
	
	printf("\n\n Total_Movements  = %d \n", total);
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
	shell(a, n);
	
	printf("\n\nHere is your sorted list by method of shell sort\n\n");
	for (i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

