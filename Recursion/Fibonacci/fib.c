// =============================================================
// Preorder traversal sequence : (root, left, right)
// Inorder traversal sequence  : (left, root, right)
// Postorder traversal sequence: (left, right, root)
// =============================================================

# include <stdio.h>
# include <stdlib.h>

int fib(int u)
{
	if (u <= 1)
	{ 
		return 1;
	}
	return (fib(u-1) + fib(u-2));
}

void main() 
{
    printf("Michael Sun: Hello World! Please a fibonacci sequence number, then return \n\n");
	
	int x;
	while (scanf("%d", &x) != EOF)
	{
		if ( x >= 0)
		{
			printf("\nFib(%d) = %d \n", x, fib(x));
		}
		
		printf("\nPlease enter another fibonacci sequence number or CTL-c to end: \n\n");
	}
}

