// Test for inc\BinaryTree.cpp 

#include "..\inc\utils.h"
#include "..\inc\BinaryTree.h"

int BinaryTreeTest() {
	int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};	
	BinaryTreeNode<int> *root = createMinimalBST<int>(arr, 0, 9);
	//printf ("Binary Tree data is %d\n", root->data);
	//root->displayNodeDFS();
	//printf("\n");
	vector< BinaryTreeNode<int>* > treeList;
	root->getNodesDFS(&treeList);
	displayTreeNodeList(&treeList);

	return 0;
}