// Utility header file for Tree data structure
// Author: Binlong Li  Date: 01/09/2016
#include "utils.h"

#include <queue>
#include <stack>

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