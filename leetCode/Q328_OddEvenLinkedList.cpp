// Given a singly linked list, group all odd nodes together followed by the even nodes.Please note here we are talking about the node number and not the value in the nodes.
// 
// You should try to do it in place.The program should run in O(1) space complexity and O(nodes) time complexity.
// 
// 
// 
// Example:
// Given 1->2->3->4->5->NULL,
// return 1->3->5->2->4->NULL.
// 
// Note :
//      The relative order inside both the even and odd groups should remain as it was in the input.
//      The first node is considered odd, the second node even and so on ...
//
// 
// Definition for singly-linked list.
// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode(int x) : val(x), next(NULL) {}
// };
// 
// class Solution {
// public:
//     ListNode* oddEvenList(ListNode* head)
//     {
// 
//     }
// };
// Author: Binlong Li 
// StartTime: 01/22/2016

#include "..\inc\utils.h"

ListNode* oddEvenList(ListNode* head)
{
    if (nullptr == head) {
        return nullptr;
    }
    // return the original list when there is only one or two elements
    if (nullptr == head->next || nullptr == head->next->next) {
        return head;
    }
    
    ListNode* oddRunner = head; 
    ListNode* newOddRunner = oddRunner;
    ListNode *operatePoint = head;

    // find the last odd node
    ListNode* runner = head->next;
    bool isEven = true;
    while (nullptr != runner->next) {
        runner = runner->next;
        isEven = !isEven;
        if (!isEven) {
            operatePoint = runner;
        }
    }
    
    // Start to insert even node behind of odd nodes
    runner = operatePoint;
    while (oddRunner != operatePoint) {
        // insert even node
        newOddRunner = oddRunner->next->next;
        oddRunner->next->next = runner->next;
        runner->next = oddRunner->next;
        // update runner and oddRunner
        runner = runner->next;
        oddRunner->next = newOddRunner;
        oddRunner = newOddRunner;
    }
    return head;
}

void printList(const ListNode* head)
{
    const ListNode* runner = head;
    while (runner) {
        printf("%d ", runner->val);
        runner = runner->next;
    }
    printf("\n");    
}
int Q328_OddEvenLinkedList()
{
    ListNode* head = new ListNode(1);
    ListNode* runner = head;
    for (int i = 2; i < 7; i++) {        
        runner->next = new ListNode(i);
        runner = runner->next;
    }
    printList(head);    
    printList(oddEvenList(head));

    runner = head;
    ListNode* anchor;
    while (runner != nullptr) {
        anchor = runner;
        runner = runner->next;
        delete anchor;
    }

    head = new ListNode(1);
    runner = head;
    for (int i = 2; i < 8; i++) {
        runner->next = new ListNode(i);
        runner = runner->next;
    }

    printf("\n");
    printList(head);
    printList(oddEvenList(head));
    
    runner = head;    
    while (runner != nullptr) {
        anchor = runner;
        runner = runner->next;
        delete anchor;
    }

    return 0;
}