// 2.1 remove all the duplicated items within the linked list. How would you do if no extra buffer could be used.
#include <iostream>
#include "..\CLinkedList.h"
#include "..\utils.h"

#define SIZE 10

int main()
{
    time_t* t = new time_t();
    srand(uint(time(t)));
    
    Node<int>* head = new Node<int>(0);
    for (int i = 0; i < SIZE; i++) {
        head->appendToTail(rand() % 5 + 1);
    }
    //head->appendToTail(2);
    //head->appendToTail(1);
    //head->appendToTail(3);
    //head->appendToTail(1);
    //head->appendToTail(1);
    //head->appendToTail(2);
    //head->appendToTail(5);
    //head->appendToTail(1);
    //head->appendToTail(3);
    //head->appendToTail(5);


    printf("The original linked list is: \n");
    head->printList();
    printf("\n");

    // Start to remove elements from the list
    Node<int>* h = head;
    Node<int> *p, *n;
    int data;

    while (h != nullptr && h->next != nullptr) {
        data = h->data;
        cout << "Working at " << data << endl;
        n = h->next;
        p = h;
        while (n != nullptr) {
            if (n->data == data) {
                p->next = n->next; 
                //delete n;
                n = p->next;  
                cout << data << ", ";                
            } else {
                p = n;
                n = n->next;
            }
        }
        h = h->next;
        cout << endl;
    }

    printf("The linked list after remove duplicate items. \n");
    head->printList();
    printf("\n");
}