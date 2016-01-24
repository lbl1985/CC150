// 4.3 Given a sorted (increasing order) array, rite an algorithm to create a binary seach 
// tree with minimal height.
// Author: Binlong Li 
// Date: 01/23/2015

#include "..\inc\utils.h"
#include "..\inc\BinaryTree.h"
#include <vector>

template<class T>
BinaryTreeNode<T>* createBinarySearchTree(const vector<T> &vec, const int start, const int end)
{
    if (start > end) {
        return nullptr;
    }

    int midIndex = (start + end) >> 1;
    BinaryTreeNode<T>* root = new BinaryTreeNode<T>(vec[midIndex]);
    root->left = createBinarySearchTree<T>(vec, start, midIndex - 1);
    root->right = createBinarySearchTree<T>(vec, midIndex + 1, end);
    return root;
}


int C4Q3(){
    vector<int> vec{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    BinaryTreeNode<int>* root = createBinarySearchTree<int>(vec, 0, vec.size() - 1);
    vector<BinaryTreeNode<int>*> vecOrder;
    root->getNodesInOrderDFS(&vecOrder);
    for (size_t i = 0; i < vecOrder.size(); i++) {
        printf("%d ", vecOrder[i]->data);
    }
	return 0;
}