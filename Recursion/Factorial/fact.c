// =============================================================
// Preorder traversal sequence : (root, left, right)
// Inorder traversal sequence  : (left, root, right)
// Postorder traversal sequence: (left, right, root)
// =============================================================

# include <stdio.h>
# include <stdlib.h>

int factorial(int u)
{
	if (u == 0)
	{ 
		return 1;
	}
	return u*factorial(u-1);
}

void main() 
{
    printf("Michael Sun: Hello World! Please a factorial number, then return \n\n");
	
	int x;
	while (scanf("%d", &x) != EOF)
	{
		if ( x >= 0)
		{
			printf("\n%d! = %d \n", x, factorial(x));
		}
		
		printf("\nPlease enter another factorial number or CTL-c to end: \n\n");
	}
}

