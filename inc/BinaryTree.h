// Utility header file for Tree data structure
// Author: Binlong Li  Date: 01/09/2016
#include "utils.h"

#include <queue>
#include <stack>
#include <vector> 

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

	S_Res getNodesDFS(vector< BinaryTreeNode<T>* >* treeList);
	S_Res getNodesBFS(vector< BinaryTreeNode<T>* >* treeList);
	
	BinaryTreeNode *left;
	BinaryTreeNode *right;
	Status st;
	T data;
};

template <class T>
BinaryTreeNode<T>* createMinimalBST(const T* arr, int startIndex, int endIndex) {
	if (NULL == arr) {
		return NULL;
	}

	if (startIndex > endIndex) {
		return NULL;
	}

	int midIndex = (startIndex + endIndex) / 2;
	int midValue = arr[midIndex];

	BinaryTreeNode<T>* root = new BinaryTreeNode<T>(midValue);
	root->left = createMinimalBST(arr, startIndex, midIndex - 1);
	root->right = createMinimalBST(arr, midIndex + 1, endIndex);
	return root;
}

template <class T>
S_Res displayTreeNodeList(const vector< BinaryTreeNode<T>* >* treeList) {
	
	for (vector< BinaryTreeNode<T>* >::const_iterator vBegin = treeList->cbegin(); vBegin != treeList->cend(); vBegin++) {
		cout << (*vBegin)->data << "\t";
	}
	return S_OK;
}

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

template<class T> S_Res BinaryTreeNode<T>::getNodesDFS( vector< BinaryTreeNode<T>* >* treeList){
	std::stack< BinaryTreeNode<T>* > s;

	this->st = visited;
	s.push(this);

	while(!s.empty()){
		BinaryTreeNode<T> * k = s.top();
		s.pop();
		if(k->right != NULL && k->right->st != visited){
			s.push(k->right);
			k->right->st = visiting;
		}
		if(k->left != NULL && k->left->st != visited){
			s.push(k->left);
			k->left->st = visiting;
		}
		k->st = visited;
		treeList->push_back(k);
	}
	return S_OK;
}

template<class T> S_Res BinaryTreeNode<T>::getNodesBFS(vector< BinaryTreeNode<T>* > *treeList) {
	if (NULL == treeList) {
		return S_Invalid;
	}

	queue< BinaryTreeNode<T> *> q;
	q.push(this);

	while (!q.empty()) {
		BinaryTreeNode<T> *tmp = q.front();
		treeList->push_back(tmp);		
		q.pop();
		if (tmp->left != NULL) {
			q.push(tmp->left);
		}
		if (tmp->right != NULL) {
			q.push(tmp->right);
		}
	}
	return S_OK;
}

