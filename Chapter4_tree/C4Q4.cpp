// 4.4 Given a binary search tree, design an algorithm which creates a linked list of
// all the nodes at each depth (e.g., if you have a tree with depth D, you will have D
// linked lists).
// Author: Binlong Li   
// Date:   01/29/2016

#include "..\inc\utils.h"
#include "..\inc\binarytree.h"
#include <vector>
#include <stack>
using namespace std;

void getList(BinaryTreeNode<int>* root, vector<vector<BinaryTreeNode<int>*> >& vNodes)
{
	if(nullptr == root){
		return;
	}
	stack<BinaryTreeNode<int>*> s;
	stack<int> sDepth;

	s.push(root);
	sDepth.push(0);
	root->st = visiting;


	while(!s.empty()){
		BinaryTreeNode<int>* cur = s.top();
		s.pop();
		int curDepth = sDepth.top();
		sDepth.pop();

		if((int)vNodes.size() < curDepth + 1){
			vector<BinaryTreeNode<int>*> tmpVec;
			vNodes.push_back(tmpVec);
		}
		vector<BinaryTreeNode<int>*>& curVec = vNodes[curDepth];

		if(cur->right != nullptr && cur->st != visited ){
			s.push(cur->right);
			sDepth.push(curDepth + 1);
			cur->right->st = visiting;
		}

		if(cur->left != nullptr && cur->st != visited){
			s.push(cur->left);
			sDepth.push(curDepth + 1);
			cur->left->st = visiting;
		}

		cur->st = visited;
		curVec.push_back(cur);
	}
}

int C4Q4(){
	int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};	
	BinaryTreeNode<int> *root = createMinimalBST<int>(arr, 0, 9);

	vector<vector< BinaryTreeNode<int>* > >	 vNodes;
	getList(root, vNodes);

	for(int i = 0; i < (int)vNodes.size(); i++){
		for(int j = 0; j < (int)vNodes[i].size(); j++){
			printf("%d ", vNodes[i][j]->data);
		}
		printf("\n");
	}
	return 0;
}