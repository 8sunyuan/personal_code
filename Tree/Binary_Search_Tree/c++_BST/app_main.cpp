#include "bst.h"

int main() 
{
	
	bst *bst_tree = NULL;
	bst_tree = new bst;
	
	bst_tree->app_interface();
	
	delete bst_tree;
	bst_tree = NULL;
	
	// bst bst_tree;
	// bst_tree.app_interface();
	
	return 0;
}