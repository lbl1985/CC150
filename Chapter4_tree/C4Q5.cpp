// 4.5 Implement a function to check if a binary tree is a binary search tree.
// Author: Binlong Li        Date: 02/01/2016
#include "..\inc\utils.h"
#include "..\inc\BinaryTree.h"
#include <stack>
#include <vector>
using namespace std;

void DFSWithoutSt(const BinaryTreeNode<int>* head, vector<const BinaryTreeNode<int>*> *treeList){
	if(nullptr == head){
		return;
	}
	stack<const BinaryTreeNode<int>*> s;
	s.push(head);

	while(!s.empty()){
		const BinaryTreeNode<int>* t = s.top();
		s.pop();

		if(t->right != nullptr){
			s.push(t->right);
		}

		if(t->left != nullptr){
			s.push(t->left);
		}
		treeList->push_back(t);
	}
}

void InOrderTraverse(const BinaryTreeNode<int>* root, vector<int> *val){
	if(root == nullptr) return;

	if(root->left != nullptr){
		InOrderTraverse(root->left, val);
	}

	val->push_back(root->data);

	if(root->right != nullptr){
		InOrderTraverse(root->right, val);
	}
}

bool isBinarySearchTree2(const vector<int> &val)
{
	for(size_t i = 0; i < val.size() - 1; i++ ){
		if(val[i] > val[i+1]){
			return false;
		}
	}
	return true;
}

bool isBinarySearchTree(const BinaryTreeNode<int>* head){
	// Use DFS to traverse the tree
	if(nullptr == head){
		return false;
	}
	stack<const BinaryTreeNode<int>*> s;
	s.push(head);	

	while(!s.empty()){
		const BinaryTreeNode<int>* t = s.top();
		s.pop();

		if(t->right != nullptr){
			s.push(t->right);
			if(t->right->data < t->data){
				return false;
			}
		}

		if(t->left != nullptr){
			s.push(t->left);
			if(t->left->data > t->data){
				return false;
			}
		}
	}

	return true;
}

int C4Q5()
{
	cout << "C4Q5 inside" << endl;
	int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	BinaryTreeNode<int>* head = createMinimalBST<int>(arr, 0, 9);

	vector<const BinaryTreeNode<int>*> treeList;
	DFSWithoutSt(head, &treeList);

	for (vector< const BinaryTreeNode<int>* >::const_iterator vBegin = treeList.cbegin(); vBegin != treeList.cend(); vBegin++) {
		cout << (*vBegin)->data << "\t";
	}

	cout << endl;

	cout << "This tree is Binary search tree: " << (isBinarySearchTree(head) ? " true" : " false") << endl;

	vector<int> vecInOrder;
	InOrderTraverse(head, &vecInOrder);

	cout << endl;
	for(size_t i = 0; i < vecInOrder.size(); i++){
		cout << vecInOrder[i] << " ";
	}
	cout << endl;

	cout << "This tree is Binary search tree for in order traverse: " << (isBinarySearchTree2(vecInOrder) ? " true" : " false") << endl;

	return 0;
}