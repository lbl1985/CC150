// 2.5 You have two numbers represented by a linked list, where each node
// contains a single digit. The digits are stored in reverse order, such 
// that the 1's digits at the head of the list. Write a function that adds
// the two numbers and returns the sum as a linked list.
// EXAMPLE:
// Input: (7 -> 1 -> 6) + (5 -> 9 -> 2) that is: 617 + 295
// Output: 2 -> 1 -> 9. That is 912
// FOLLOW UP:
// Suppose the digits are stored in forward order. Repeat the above problem.
// EXAMPLE:
// Input: (6 -> 1 -> 7) + (2 -> 9 -> 5) that is: 617 + 295
// Output: 9 -> 1 -> 2. That is 912

// 
// Section 2, test case: 9653 + 653
// 

#include "..\utils.h"

int main()
{
    Node<int> *l1 = new Node<int>(9);
    l1->appendToTail(6);
    l1->appendToTail(5);
    l1->appendToTail(3);

    Node<int> *l2 = new Node<int>(6);
    l2->appendToTail(5);
    l2->appendToTail(3);
        
    std::cout << "print list l1 is: "; 
    l1->printList();
    std::cout << "print list l2 is: ";
    l2->printList();
    std::cout << "L1Num in Ascend order is: " << linkedListToNumAscOrder<int>(l1) << std::endl;
    std::cout << "L2Num in Ascend order is: " << linkedListToNumAscOrder<int>(l2) << std::endl;
    std::cout << "l1Num in Descend order is: " << linkedListToNumDesOrder<int>(l1) << std::endl;
    std::cout << "l2Num in Descend order is: " << linkedListToNumDesOrder<int>(l2) << std::endl;
    std::cout << "L1 size is: " << l1->size() << std::endl;
    std::cout << "L2 size is: " << l2->size() << std::endl;
    return 0;
}