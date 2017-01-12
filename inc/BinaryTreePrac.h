#pragma once
#ifndef BINARYTREEPRAC_H
#define BINARYTREEPRAC_H


#include "BinaryTree.h"


template<class T>
BinaryTreeNode<T>* CreateMinBinaryTree(T* arr, int start, int end)
{
	if (arr == NULL) {
		return NULL;
	}
	if (start > end) {
		return NULL;
	}
	int mid = (start + end) / 2;
	BinaryTreeNode<T>* root = new BinaryTreeNode<T>(arr[mid]);
	root->left = CreateMinBinaryTree(arr, start, mid - 1);
	root->right = CreateMinBinaryTree(arr, mid + 1, end);
	return root;
}
#endif // !BINARYTREEPRAC_H