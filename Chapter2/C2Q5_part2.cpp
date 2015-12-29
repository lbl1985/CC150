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

#include "..\utils.h"

int main()
{
    Node<int> *l1 = new Node<int>(9);
    l1->appendToTail(6);
    l1->appendToTail(5);
    l1->appendToTail(3);

    int l1Num= linkedListToNumAscOrder<int>(l1);
    std::cout << "l1Num is: " << l1Num << std::endl;
    return 0;
}