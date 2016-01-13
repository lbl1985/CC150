// 4.1 Implement a function to check if a binary tree is balanced. for purpose of
// this question, a balanced tree is defined to be a tree such that the heights of the
// two subtrees of any node never differ by more than one

#include "..\inc\utils.h"
#include "..\inc\BinaryTree.h"

bool checkBalanceTree(const BinaryTreeNode<int>* root, int* depth) {
	if (NULL == root) {
		*depth = 0;
		return true;
	}

	int depthLeft = 0, depthRight = 0;

	
	if (NULL != root->left) {		
		if (!checkBalanceTree(root->left, &depthLeft)) {
			return false;
		}
	}

	if (NULL != root->right) {
		if (!checkBalanceTree(root->right, &depthRight)) {
			return false;
		}
	}

	*depth = depthLeft > depthRight ? 1 + depthLeft : 1 + depthRight;

	if (abs(depthLeft - depthRight) > 1) {
		return false;
	}
	return true;

}

int C4Q1() {
	int arr[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	BinaryTreeNode<int>* root = createMinimalBST<int>(arr, 0, 9);
	int depth=0;
	bool isBal = checkBalanceTree(root, &depth);
	printf("root is balanced tree? %s", isBal ? "yes" : "no");
	printf("\nThe tree depth is %d\n", depth);
	return 0;
}