// Test the basic implementation of Linked List

#include <iostream>
#include "..\CLinkedList.h"

int main()
{
    Node<int>* head = new Node<int>(0);
    for (int i = 1; i < 10; i++) {
        head->appendToTail(i);
    }

    head->printList();
    delete head;

    return 0;
}