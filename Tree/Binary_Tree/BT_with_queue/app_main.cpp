#include "binaryTree.h"

int main() 
{
	
	binaryTree *bst_tree = NULL;
	bst_tree = new binaryTree;
	
	bst_tree->app_interface();
	
	delete bst_tree;
	bst_tree = NULL;
	
	// bst bst_tree;
	// bst_tree.app_interface();
	
	return 0;
}