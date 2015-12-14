// 2.2 find the last Kth item a single listed linked list
#include <iostream>
#include "..\CLinkedList.h"
#include <time.h>
#include <stdlib.h>

#define SIZE 10
#define R_OK 0
#define R_INVALIDARGUMENT 1

typedef unsigned int uint;

int printTheLastKthItem(Node<int>* head, int k)
{
    if (head == nullptr) {
        return R_INVALIDARGUMENT;
    }
    Node<int>* anchor = head;
    Node<int>* runner = head;

    // put runner kth element ahead
    int i = 0; 
    while (i++ < (k-1) && runner->next != nullptr) {
        runner = runner->next;
    }

    // k is larger than length of the list
    if (i < k - 1) {
        return R_INVALIDARGUMENT;
    }

    // runner and anchor running together
    while (runner->next != nullptr) {
        anchor = anchor->next;
        runner = runner->next;
    }

    cout << "the " << k << "th last element is: " << anchor->data << endl;
    return R_OK;
}

int main()
{
    srand(uint(time(nullptr)));
    Node<int> *head = new Node<int>(rand() % 10 );
    

    for (int i = 0; i < SIZE - 1; i++) {
        head->appendToTail(rand() % 10);
    }
    printf("original linked list is: \n");
    head->printList();

    printf("\n");
    printTheLastKthItem(head, 3);

    return 0;
}