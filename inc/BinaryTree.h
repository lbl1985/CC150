// Utility header file for Tree data structure
// Author: Binlong Li  Date: 01/09/2016
#include "utils.h"

#include <queue>
#include <stack>

const bool isDebug = true;

enum Status {
	Unvisited = 0,
	visiting,
	visited
};

template <class T>
class BinaryTreeNode {
public:
	BinaryTreeNode<T>();

	BinaryTreeNode<T>(T d);

	BinaryTreeNode<T>& operator = (const BinaryTreeNode<T> &other);

	static BinaryTreeNode<T>* createMinimalBST(const T* arr, int startIndex, int endIndex);

	BinaryTreeNode *left;
	BinaryTreeNode *right;
	Status st;
	T data;
};

template<class T> BinaryTreeNode<T>::BinaryTreeNode(){
	left = NULL;
	right = NULL;
	data = 0;
	st = Unvisited;
}

template<class T> BinaryTreeNode<T>::BinaryTreeNode(T d){
	data = d;
	left = NULL;
	right = NULL;
	st = Unvisited;	
}

template<class T> BinaryTreeNode<T>& BinaryTreeNode<T>::operator = (const BinaryTreeNode<T> &other){
	if(&other == this){
		return other;
	}

	left = other.left;
	right = other.right;
	st = other.st;
	data = other.data;
}

template <class T> BinaryTreeNode<T>* BinaryTreeNode<T>::createMinimalBST(const T* arr, int startIndex, int endIndex){
	if(NULL == arr){
		if(isDebug)	printf("return error arr is NULL\n");
		return NULL;
	}

	if(startIndex > endIndex){
		if(isDebug) printf("return startIndex > endIndex\n");
		return NULL;
	}

	int midIndex = (startIndex + endIndex) / 2;
	int midValue = arr[midIndex];

	BinaryTreeNode<T> *root = new BinaryTreeNode<T>(midValue);
	if(isDebug) printf("create node %d \n", midValue);
	root->left = createMinimalBST(arr, startIndex , midIndex - 1);
	root->right = createMinimalBST(arr, midIndex + 1, endIndex);
	return root;
}