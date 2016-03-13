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
	if(l1->val <= l2->val){
		res = l1;
	} else {
		res = l2;
	}


	ListNode* tmp = NULL;
	
	while(l1 != NULL && l2 != NULL){
		if(l1->val <= l2->val){
			tmp = l1->next;			
			l1->next = l2;
			l2 = l2->next;
			l1->next->next = tmp;
			l1 = tmp;
		} else {
			tmp = l2->next;
			l2->next = l1;
			l1 = l1 -> next;
			l2->next->next = tmp;
			l2 = tmp;
		}
	}
	return res;
}

int Q021_Merge_Two_Sorted_Lists(){
	printf("inside of Q021_Merge_Two_Sorted_Lists\n");
	return 0;
}