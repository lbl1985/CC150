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

// The current implement is correct, but this may not be ideal
// it's better to reimplement this question. 

#include <iostream>
#include "..\utils.h"
#include "..\CLinkedList.h"
#include <time.h>
#include <stdlib.h>

int linkedListToNumber(const Node<int>* l)
{
    int count = 0;
    int num = 0;
    while (l) {
        num += l->data * (int)(pow(10, count++));
        l = l->next;
    }
    return num;
}

Node<int>* NumberToLinkedList(int num)
{    
    Node<int>* head = new Node<int>(num % 10);
    num = num / 10;
    int count = 2;
    while (num) {        
        head->appendToTail(num % 10);
        num /= 10;
    }
    
    return head;
}

int addTwoLinkedList(const Node<int>* a, const Node<int>*b)
{
    int aNum = linkedListToNumber(a);
    int bNum = linkedListToNumber(b);

    return aNum + bNum;
}


int main()
{
    Node<int> *a = new Node<int>(7);
    a->appendToTail(1);
    a->appendToTail(6);
    a->appendToTail(5);

    Node<int> *b = new Node<int>(5);
    b->appendToTail(9);
    b->appendToTail(2);

    printf("a is:");
    a->printList();

    printf("b is:");
    b->printList();

    int res = addTwoLinkedList(a, b);

    Node<int> *c = NumberToLinkedList(res);

    cout << linkedListToNumber(a) << " + " << linkedListToNumber(b) << " = " << linkedListToNumber(c) << endl;

    a->deallocateWholeLinkedList();
    b->deallocateWholeLinkedList();
    c->deallocateWholeLinkedList();
}
