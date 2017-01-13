#pragma once
#ifndef BINARYTREEPRAC_H
#define BINARYTREEPRAC_H


// #include "BinaryTree.h"
#include <queue>
#include <stack>
#include <vector>

using namespace std;

class Node_prac{
public:
	int data;
	Node_prac* left;
	Node_prac* right;
	Node_prac(int _v):data(_v), left(NULL), right(NULL){}
};

Node_prac* CreateMinBinaryTree_p(int* arr, int start, int end)
{
	if (arr == NULL) {
		return NULL;
	}

	if(start > end){
		return NULL;
	}

	int mid = (start + end) / 2;
	Node_prac* root = new Node_prac(arr[mid]);
	root->left = CreateMinBinaryTree_p(arr, start, mid - 1);
	root->right = CreateMinBinaryTree_p(arr, mid + 1, end);
	return root;
}

void inOrderTraverse(Node_prac* root){
	if(root != NULL){
		inOrderTraverse(root->left);
		printf("%d ", root->data);
		inOrderTraverse(root->right);
	}
}

void preOrderTraverse(Node_prac* root) {
	if(root != NULL) {
		printf("%d ", root->data);
		preOrderTraverse(root->left);
		preOrderTraverse(root->right);
	}
}

void postOrderTraverse(Node_prac* root){
	if(root != NULL){
		postOrderTraverse(root->left);
		postOrderTraverse(root->right);
		printf("%d ", root->data);
	}
}

void DFT(Node_prac* root, stack<Node_prac*>& s){
	if(root != NULL){
		s.push(root);
	}

	Node_prac* tmp = s.top();
	if(tmp->left != NULL) {
		DFT(tmp->left, s);
	}
	if(tmp->right != NULL) {
		DFT(tmp->right, s);
	}

	printf("%d ", tmp->data);
	s.pop();


	// if(root != NULL){
	// 	s.push(root);
	// 	if(root->left != NULL) {
	// 		DFT(root->left, s);
	// 	}
	// 	if(root->right != NULL) {
	// 		DFT(root->right, s);
	// 	}		
	// }
}

void BFT(Node_prac* root, queue<Node_prac*>& q){
	if(root != NULL){
		q.push(root);
	}
	while(!q.empty()){
		Node_prac* tmp = q.front();
		if(tmp->left != NULL) {
			q.push(tmp->left);
		}
		if(tmp->right != NULL){
			q.push(tmp->right);
		}
		printf("%d ", tmp->data);
		q.pop();
	}
}

// template<class T>
// BinaryTreeNode<T>* CreateMinBinaryTree(T* arr, int start, int end)
// {
// 	if (arr == NULL) {
// 		return NULL;
// 	}
// 	if (start > end) {
// 		return NULL;
// 	}
// 	int mid = (start + end) / 2;
// 	BinaryTreeNode<T>* root = new BinaryTreeNode<T>(arr[mid]);
// 	root->left = CreateMinBinaryTree(arr, start, mid - 1);
// 	root->right = CreateMinBinaryTree(arr, mid + 1, end);
// 	return root;
// }
#endif // !BINARYTREEPRAC_H