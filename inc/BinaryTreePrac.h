#pragma once
#ifndef BINARYTREEPRAC_H
#define BINARYTREEPRAC_H


// #include "BinaryTree.h"
#include <queue>
#include <stack>
#include <vector>

using namespace std;

class Node{
public:
	int data;
	Node* left;
	Node* right;
	Node(int _v):data(_v), left(NULL), right(NULL){}
};

Node* CreateMinBinaryTree(int* arr, int start, int end)
{
	if (arr == NULL) {
		return NULL;
	}

	if(start > end){
		return NULL;
	}

	int mid = (start + end) / 2;
	Node* root = new Node(arr[mid]);
	root->left = CreateMinBinaryTree(arr, start, mid - 1);
	root->right = CreateMinBinaryTree(arr, mid + 1, end);
	return root;
}

void inOrderTraverse(Node* root){
	if(root != NULL){
		inOrderTraverse(root->left);
		printf("%d ", root->data);
		inOrderTraverse(root->right);
	}
}

void preOrderTraverse(Node* root) {
	if(root != NULL) {
		printf("%d ", root->data);
		preOrderTraverse(root->left);
		preOrderTraverse(root->right);
	}
}

void postOrderTraverse(Node* root){
	if(root != NULL){
		postOrderTraverse(root->left);
		postOrderTraverse(root->right);
		printf("%d ", root->data);
	}
}

void DFT(Node* root, stack<Node*>& s){
	if(root != NULL){
		s.push(root);
		if(root->left != NULL) {
			DFT(root->left, s);
		}
		if(root->right != NULL) {
			DFT(root->right, s);
		}		
	}
}

void BFT(Node* root, queue<Node*>& q){
	if(root != NULL) {
		q.push 	(root);
		if(root->left != NULL){
			q.push 	(root->left);
		}
		if(root->right != NULL) {
			q.push 	(root->right);
		}
		if(root->left != NULL){
			BFT(root->left, q);
		}
		if(root->right != NULL){
			BFT(root->right, q);
		}
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