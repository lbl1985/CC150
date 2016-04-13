// Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
// 
// Subscribe to see which companies asked this question
// 
// /**
//  * Definition for singly-linked list.
 // * struct ListNode {
 // *     int val;
 // *     ListNode *next;
 // *     ListNode(int x) : val(x), next(NULL) {}
 // * };
//  */
// class Solution {
// public:
//     ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
//         
//     }
// };
// Author: Binlong Li
// Date:   03/10/2016
#include "..\inc\utils.h"
#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
	if(nullptr == l1){
		return l2;
	}
	if(nullptr == l2){
		return l1;
	}

	ListNode* res = NULL;
	ListNode* l1Runner = l1;
	ListNode* l2Runner = l2;

	if(l1->val <= l2->val){
		res = l1;
		l1Runner = l1Runner->next;
	} else {
		res = l2;
		l2Runner = l2Runner->next;
	}


	ListNode* resRunner= res;

	while(l1Runner != NULL && l2Runner != NULL){
		if(l1Runner->val <= l2Runner->val){
			resRunner->next = l1Runner;			
			l1Runner = l1Runner->next;
			resRunner = resRunner->next;
		} else {
			resRunner->next = l2Runner;
			l2Runner = l2Runner->next;
			resRunner = resRunner->next;
		}
	}

	while(l1Runner != NULL){
		resRunner->next = l1Runner;		
		l1Runner = l1Runner->next;
		resRunner = resRunner->next;
	}

	while(l2Runner != NULL){
		resRunner->next = l2Runner;
		l2Runner = l2Runner->next;
		resRunner = resRunner->next;
	}

	return res;
}

ListNode* createList(const vector<int>& arr)
{
	ListNode* res = NULL;
	size_t n = arr.size();
	if(n >= 1){
		res = new ListNode(arr[0]);
	}
	
	ListNode* resRunner = res;

	for(size_t i = 1; i < n; i++){
		resRunner->next = new ListNode(arr[i]);
		resRunner = resRunner->next;
	}
	return res;
}

void releaseList(ListNode* root)
{
	ListNode* tmpRoot = NULL;
	while(root){
		tmpRoot = root->next;
		delete root;
		root = tmpRoot;
	}
}

void printListNodes(const ListNode* root)
{
	while(root){
		printf("%d ", root->val);
		root = root->next;
	}
	printf("\n");
}

int Q021_Merge_Two_Sorted_Lists(){
	printf("Test case 1\n");
	
	vector<int> test_in1{1, 3, 4};
	vector<int> test_in2{0};
	ListNode* test_l1 = createList(test_in1);
	printListNodes(test_l1);
	ListNode* test_l2 = createList(test_in2);
	printListNodes(test_l2);
	ListNode* res_test1 = mergeTwoLists(test_l1, test_l2);
	printListNodes(res_test1);
	releaseList(test_l1);
	releaseList(test_l2);


	return 0;
}