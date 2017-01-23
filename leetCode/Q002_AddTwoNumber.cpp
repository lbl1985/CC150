// You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

// You may assume the two numbers do not contain any leading zero, except the number 0 itself.

// Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
// Output: 7 -> 0 -> 8

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int advance = 0;
        bool first = true;
        ListNode* lr;
        ListNode* root;
        while(l1 != NULL && l2 != NULL) {
            if(first) {
                lr = new ListNode(l1->val + l2->val + advance);
                root = lr;
                first = false;
            } else {
                lr ->next = new ListNode(l1->val + l2->val + advance);
                lr = lr->next;
            }
            if(lr->val >= 10) {
                lr->val = lr->val % 10;
                advance = 1;
            } else {
                advance = 0;
            }
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1 != NULL) {
            lr->next  = new ListNode(l1->val + advance);
            lr = lr->next;
            if(lr->val >= 10) {
                lr->val = lr->val % 10;
                advance = 1;
            } else {
                advance = 0;
            }
            l1 = l1->next;
        }
        while(l2 != NULL) {
            lr->next = new ListNode(l2->val + advance);
            lr = lr->next;
            if(lr->val >= 10) {
                lr->val = lr->val % 10;
                advance = 1;
            } else {
                advance = 0;
            }
            l2 = l2->next;
        }
        if(advance == 1) {
            lr->next = new ListNode(1);
        }
        return root;
    }
};