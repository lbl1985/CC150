// 2.7 implement a function to check if a linked list is a palindrome
// palindrome exapmle 1: a -> b -> c -> d -> c -> b -> a
// palindrome example 2: a -> b -> c -> c -> b -> a

#include "..\inc\utils.h"
#include <stack>

bool isPalindrome(const Node<int>* head)
{
    if(NULL == head) {
        return true;
    }

    stack<const Node<int>* >  buffer;

    const Node<int>* slow = head;
    const Node<int>* fast = head;
    while(fast->next != NULL) {
        buffer.push(slow);
        if(fast->next->next == NULL) {
            break;
        }
        slow = slow->next;
        fast = fast->next->next;
    }

    slow = slow->next;
    while(!buffer.empty() && slow) {
        if(buffer.top()-> data != slow->data) {
            return false;
        }
        buffer.pop();
        slow = slow->next;
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

    int arr2[7] = { 1, 2, 3, 4, 3, 2, 1};
    Node<int>* head2 = new Node<int>(arr, 7);
    std::cout << "Test case 2: " << std::endl;
    head2->printList();
    std::cout << " is palindrome: " << (isPalindrome(head2) ? "true" : "false");

    return 0;
}
