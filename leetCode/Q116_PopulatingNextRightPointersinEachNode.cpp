// Given a binary tree 
//     struct TreeLinkNode {
//       TreeLinkNode *left;
//       TreeLinkNode *right;
//       TreeLinkNode *next;
//     }
// 
// 
// 
// Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.
// 
// Initially, all next pointers are set to NULL.
// 
// Note: 
// •You may only use constant extra space.
// •You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and every parent has two children).
// 
// 
// For example,
//  Given the following perfect binary tree,
// 
//          1
//        /  \
//       2    3
//      / \  / \
//     4  5  6  7
// 
// 
// 
// After calling your function, the tree should look like:
// 
//          1 -> NULL
//        /  \
//       2 -> 3 -> NULL
//      / \  / \
//     4->5->6->7 -> NULL
// 
/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
// class Solution {
// public:
//     void connect(TreeLinkNode *root) {
        
//     }
// };
// Author: Binlong Li
// Date: 02/26/2016

#include "..\inc\utils.h"
#include <vector>
#include <queue>
using namespace std;
#define DEBUG 1

struct TreeLinkNode {
 int val;
 TreeLinkNode *left, *right, *next;
 TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

#if DEBUG
TreeLinkNode* CreateExample1()
{
	TreeLinkNode *root = new TreeLinkNode(1);
	root->left = new TreeLinkNode(2);
	root->right = new TreeLinkNode(3);
	root->left->left = new TreeLinkNode(4);
	root->left->right = new TreeLinkNode(5);
	root->right->left = new TreeLinkNode(6);
	root->right->right = new TreeLinkNode(7);
	return root;
}

void InOrderTree(TreeLinkNode* root, vector<TreeLinkNode*> *list){
	if(root != nullptr){
		InOrderTree(root->left, list);
		list->push_back(root);
		InOrderTree(root->right, list);
	}
}

void PreOrderTree(TreeLinkNode* root, vector<TreeLinkNode*> *list){
	if(root != nullptr){
		list->push_back(root);
		PreOrderTree(root->left, list);
		PreOrderTree(root->right, list);
	}
}

void BFSTraverse(TreeLinkNode* root, vector<TreeLinkNode*> *list){	
	if(root != nullptr){
		queue<TreeLinkNode*> q;
		q.push(root);
		while(!q.empty()){
			TreeLinkNode* tmp = q.front();
			q.pop();
			list->push_back(tmp);

			if(tmp->left != nullptr){
				q.push(tmp->left);				
			}
			if(tmp->right != nullptr){
				q.push(tmp->right);	
			}			
		}
	}
}

void printList(const vector<TreeLinkNode*>& list)
{
	size_t len = list.size();
	for(size_t i = 0; i < len; i++){
		TreeLinkNode* tmp = list[i];
		if(tmp->next == NULL){
			printf("%d Next: NULL\n", tmp->val);
		} else {
			printf("%d Next: %d\n", tmp->val, tmp->next->val);
		}		
	}
}

void printList(const vector<TreeLinkNode*>& list, const vector<int>& depth)
{
	size_t len = list.size();
	if(len != depth.size()){
		printf("Error len of list and depth is not equal\n");		
		return;
	}
	for(size_t i = 0; i < len; i++){
		TreeLinkNode* tmp = list[i];
		if(tmp->next == NULL){
			printf("%d, depth %d Next: NULL\n", tmp->val, depth[i]);
		} else {
			printf("%d, depth %d Next: %d\n", tmp->val, depth[i], tmp->next->val);
		}		
	}
}

#endif

void BFSTraverse(TreeLinkNode* root, vector<TreeLinkNode*> *list, vector<int> *depth){	
	if(root != nullptr){		
		queue<TreeLinkNode*> q;
		queue<int> depthQ;
		
		q.push(root);
		depthQ.push(0);
		
		while(!q.empty()){
			TreeLinkNode* tmp = q.front();
			int tmpDepth = depthQ.front();
			
			q.pop();
			depthQ.pop();
			
			list->push_back(tmp);
			depth->push_back(tmpDepth);


			if(tmp->left != nullptr){
				q.push(tmp->left);		
				depthQ.push(tmpDepth + 1);
			}
			if(tmp->right != nullptr){
				q.push(tmp->right);	
				depthQ.push(tmpDepth + 1);
			}			
		}
	}
}

// Another derivation of BFS
void connect(TreeLinkNode *root)
{
	if(root != nullptr){
		vector<TreeLinkNode*> traveseQueue;
		vector<int> DepthQueue;
		BFSTraverse(root, &traveseQueue, &DepthQueue);
		size_t len = traveseQueue.size();
		for(size_t i = 0; i < len - 1; i++){
			TreeLinkNode* curNode = traveseQueue[i];
			TreeLinkNode* nextNode = traveseQueue[i+1];
			if(DepthQueue[i] == DepthQueue[i + 1]){
				curNode->next = nextNode;
			}
		}
	}
}

int Q116_PopulatingNextRightPointersinEachNode()
{
	printf("inside of function Q116_PopulatingNextRightPointersinEachNode\n");
	TreeLinkNode *root = CreateExample1();

	vector<TreeLinkNode*> list;
	vector<int> depth;
	BFSTraverse(root, &list, &depth);
	connect(root);
	printList(list, depth);

	return 0;
}