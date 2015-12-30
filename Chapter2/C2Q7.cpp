// 2.7 implement a function to check if a linked list is a palindrome
// palindrome exapmle 1: a -> b -> c -> d -> c -> b -> a
// palindrome example 2: a -> b -> c -> c -> b -> a

#include "..\inc\utils.h"
#include <stack>

bool isPalindrome(const Node<int>* head)
{
    if (nullptr == head) {
        return false;
    }

    const Node<int>* p = head;
    std::stack<int> stk;
    while (p) {
        stk.push(p->data);
        p = p->next;
    }

    p = head;
    while (p) {
        if (stk.top() == p->data) {
            stk.pop();
            p = p->next;
        } else {
            return false;
        }
    }
    return true;
}

int C2Q7()
{
    int arr[8] = { 1, 2, 3, 4, 3, 2, 1, 5 };
    Node<int>* head = new Node<int>(arr, 8);

    std::cout << "Test case 1: " << std::endl;
    head->printList();
    std::cout << " is palindrome: " << (isPalindrome(head) ? "true" : "false");

    return 0;
}
