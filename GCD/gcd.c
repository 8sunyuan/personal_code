// =============================================================
// Preorder traversal sequence : (root, left, right)
// Inorder traversal sequence  : (left, root, right)
// Postorder traversal sequence: (left, right, root)
// =============================================================

# include <stdio.h>
# include <stdlib.h>

int gcd(int u, int v)
{
	int t;
	while (u > 0)
	{
		if (u < v)
		{ 
			t = u; 
			u = v; 
			v = t; 
		}
		u = u-v;
	}
	
	return v;
}

void main() 
{
    printf("Michael Sun: Hello World! Please enter two numbers with space, then return \n\n");
	
	int x, y;
	while (scanf("%d %d", &x, &y) != EOF)
	{
		if (x>0 && y>0)
		{
			printf("%d %d %d\n", x, y, gcd(x,y));
		}
	}
}