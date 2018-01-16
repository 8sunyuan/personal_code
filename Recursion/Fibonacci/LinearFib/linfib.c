// =============================================================
// Preorder traversal sequence : (root, left, right)
// Inorder traversal sequence  : (left, root, right)
// Postorder traversal sequence: (left, right, root)
// =============================================================

# include <stdio.h>
# include <stdlib.h>

#define max 1000
unsigned long fib(long u)
{
	int i;
	unsigned long F[max];
	F[0] = 1;
	F[1] = 1;
	
	if (u < max)
	{
		for (i = 2; i<= u; i++)
		{ 
			F[i] = F[i-1] + F[i-2];
		}
	}
	else
	{
		printf("Input number is too big! \n");
	}
	
	return F[u];
}

void main() 
{
    printf("Michael Sun: Hello World! Please a fibonacci sequence number less than max = %d, then return \n\n", max);
	
	int x;
	while (scanf("%d", &x) != EOF)
	{
		if ( x >= 0)
		{
			printf("\nFib(%d) = %u \n", x, fib(x));
		}
		
		printf("\nPlease enter another fibonacci sequence number or CTL-c to end: \n\n");
	}
}

