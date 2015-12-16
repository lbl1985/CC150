// 2.4 Write code to partition a linked list around a value x, 
// such that all nodes less than x come before all nodes greater 
// than or equal to x

#include <iostream>
#include "..\utils.h"
#include "..\CLinkedList.h"
#include <time.h>
#include <stdlib.h>

#define SIZE 20
using namespace std;

void partitionLinkedList(Node<int>* head, int val)
{
    Node<int> *anchor = head;
    Node<int> *anchorPrev = nullptr;
    Node<int> *runner = head;

    while (runner != nullptr) {
        
        if (runner->data < val) {
            // move the value to anchor
            if (anchorPrev == nullptr) {
                // The first item is less than val
                anchorPrev = anchor;
                anchor = anchor->next;
                runner = runner->next;
            } else {                
                anchorPrev->next = runner;
                runner = runner->next;
                anchorPrev->next->next = anchor;
                anchorPrev = anchorPrev->next;
            }
            // anchor should always point to the first value larger than val
        } else {
            // runner move to the next node
            runner = runner->next;
        }
    }
}

int main()
{
    srand(uint(time(NULL)));
    Node<int> *head = new Node<int>(rand() % 10);
    for (int i = 0; i < SIZE; i++) {
        head->appendToTail(rand() % 10);
    }

    printf("The original list is:\n");
    head->printList();

    int value = 5;
    partitionLinkedList(head, value);

    printf("after partition: \n");
    head->printList();

    head->deallocateWholeLinkedList();
}