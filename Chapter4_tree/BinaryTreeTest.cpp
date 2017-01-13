// Test for inc\BinaryTree.cpp 

// #include "..\inc\utils.h"
// #include "..\inc\BinaryTree.h"
#include "..\inc\BinaryTreePrac.h"

// int BinaryTreeTest() {
// 	int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};	
// 	BinaryTreeNode<int> *root = CreateMinBinaryTree<int>(arr, 0, 9);
// 	//printf ("Binary Tree data is %d\n", root->data);
// 	//root->displayNodeDFS();
// 	//printf("\n");
// 	vector< BinaryTreeNode<int>* > treeList;
// 	root->getNodesDFS(&treeList);
// 	printf("displayNodeDFS:\n");
// 	displayTreeNodeList(&treeList);
// 	printf("\n");

// 	treeList.clear();
// 	root->getNodesBFS(&treeList);
// 	printf("displayNodeBFS:\n");
// 	displayTreeNodeList(&treeList);
// 	printf("\n");

// 	treeList.clear();
// 	printf("displayInOrderDFS\n");
// 	root->getNodesInOrderDFS(&treeList);
// 	displayTreeNodeList(&treeList);
// 	printf("\n");

// 	treeList.clear();
// 	printf("displayPreOrderDFS\n");
// 	root->getNodesPreOrderDFS(&treeList);
// 	displayTreeNodeList(&treeList);
// 	printf("\n");

// 	treeList.clear();
// 	printf("displayPostOrderDFS\n");
// 	root->getNodesPostOrderDFS(&treeList);
// 	displayTreeNodeList(&treeList);
// 	printf("\n");
// 	return 0;
// }

int BinaryTreeTest_prac(){
	int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	Node* root = CreateMinBinaryTree(arr, 0, 9);
	printf("prac inOrder Traverse:\n");
	inOrderTraverse(root);
	printf("prac PreOrder Traverse:\n");
	preOrderTraverse(root);
	printf("prac PostOrder Traverse\n");
	postOrderTraverse(root);
	stack<Node*> s;
	DFT(root, s);
	printf("prac: DFTraverse:");
	while(!s.empty()){
		Node* tmp = s.top();
		printf("%d ", tmp->data);
		s.pop();
	}
	queue<Node*> q;
	BFT(root, q);
	printf("prac: BFTraverse");
	while(!q.empty()){
		Node* tmp = q.front();
		printf("%d", tmp->data);
		q.pop();
	}
	return 0; 
}