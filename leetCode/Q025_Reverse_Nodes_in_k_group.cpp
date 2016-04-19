// Given a linked list, reverse the nodes of a linked list k at a time and return its modified list. 
// 
// If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.
// 
// You may not alter the values in the nodes, only nodes itself may be changed.
// 
// Only constant memory is allowed.
// 
// For example,
//  Given this linked list: 1->2->3->4->5 
// 
// For k = 2, you should return: 2->1->4->3->5 
// 
// For k = 3, you should return: 3->2->1->4->5 
// 
// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode(int x) : val(x), next(NULL) {}
//  * };
//  */
// class Solution {
// public:
//     ListNode* reverseKGroup(ListNode* head, int k) {
//         
//     }
// };
// 
// Author: Binlong Li
// Date: 04/14/2016

#include "..\inc\utils.h"

ListNode* reverseKGroup(ListNode* head, int k)
{
	return head;
}

int Q025_Reverse_Nodes_in_k_group()
{
	printf ("print Q025_Reverse_Nodes_in_k_group from inside\n");
	printf("test case 1\n");
	vector<int> vt1{1, 2, 3, 4, 5};
	ListNode* lt1 = createList(vt1);
	lt1 = reverseKGroup(lt1, 2);
	printListNodes(lt1);
	releaseList(lt1);

	printf("\ntest case 2\n");
	ListNode* lt2 = createList(vt1);
	lt2 = reverseKGroup(lt2, 3);
	printListNodes(lt2);
	releaseList(lt2);

	return 0;
}