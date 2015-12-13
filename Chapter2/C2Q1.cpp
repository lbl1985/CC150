// 2.1 remove all the duplicated items within the linked list. How would you do if no extra buffer could be used.
#include <iostream>
#include "..\CLinkedList.h"
#include "..\utils.h"

#define SIZE 10

// p is the previous node
void removeOneNode(Node<int>* p, Node<int>* c)
{
    p->next = c->next;
    c->next = nullptr;
    c->data = 0;
    delete c;
}

int main()
{
    time_t* t = new time_t();
    srand(uint(time(t)));
    
    Node<int>* head = new Node<int>(0);
    for (int i = 0; i < SIZE; i++) {
        head->appendToTail(rand() % 5 + 1);
    }

    printf("The original linked list is: \n");
    head->printList();
    printf("\n");

    // Start to remove elements from the list
    Node<int>* h = head;
    Node<int>* p = head;
    Node<int>* n = h->next;
    int data;

    while (h != nullptr) {
        data = h->data;
        p = h;
        while (n != nullptr) {
            if (n->data == data) {
                removeOneNode(p, n);
                n = p->next;
            } else {
                p = n;
                n = n->next;
            }
        }
        h = h->next;
    }

    printf("The linked list after remove duplicate items. \n");
    head->printList();
    printf("\n");
}