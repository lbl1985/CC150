#pragma once
#ifndef BINARYTREEPRAC_H
#define BINARYTREEPRAC_H


// #include "BinaryTree.h"
#include <queue>
#include <stack>
#include <vector>

using namespace std;

class Node_p{
public:
	int data;
	Node_p* left;
	Node_p* right;
	Node_p(int _v):data(_v), left(NULL), right(NULL){}
};

Node_p* CreateMinBinaryTree_p(int* arr, int start, int end)
{	
	if(start <= end) {
		int mid = (start + end) / 2;
		Node_p* root = new Node_p(arr[mid]);
		root->left = CreateMinBinaryTree_p(arr, start, mid - 1);
		root->right = CreateMinBinaryTree_p(arr, mid + 1, end);
		return root;
	}
	return NULL;
}

void inOrderTraverse(Node_p* root){
	if(root != NULL) {
		inOrderTraverse(root->left);
		printf("%d ", root->data);
		inOrderTraverse(root->right);
	}
}

void preOrderTraverse(Node_p* root) {
	if(root != NULL) {
		printf("%d ", root->data);
		preOrderTraverse(root->left);
		preOrderTraverse(root->right);
	}
}

void postOrderTraverse(Node_p* root){
	if(root != NULL) {
		postOrderTraverse(root->left);
		postOrderTraverse(root->right);
		printf("%d ", root->data);
	}
}

void DFT(Node_p* root){
	if(root != NULL) {
		stack<Node_p*> s;
		s.push(root);
		while(!s.empty()) {
			Node_p* top = s.top();
			printf("%d ", top->data);
			s.pop();
			if(top->right) {
				s.push(top->right);
			}
			if(top->left) {
				s.push(top->left);
			}
		}
	}
}

void BFT(Node_p* root){
	if(root != NULL) {
		queue<Node_p *> q;
		q.push(root);
		while(!q.empty()) {
			Node_p *front = q.front();
			printf("%d ", front->data);
			q.pop();
			if(front->left) {
				q.push(front->left);
			}
			if(front->right) {
				q.push(front->right);
			}
		}
	}
}

#endif // !BINARYTREEPRAC_H