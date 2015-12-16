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

void partitionLinkedList(Node<int>** head, int val)
{
    Node<int> *anchor = *head;
    Node<int> *anchorPrev = nullptr;
    Node<int> *runner;

    // anchor will be the first element larger than or equal to val (threshold)
    while (anchor != nullptr) {
        if (anchor->data < val) {
            // anchorprev will be the last element less than val (threshold)
            anchorPrev = anchor;
            anchor = anchor->next;
        } else {
            break;
        }

    }
    
    // runner will start to run from the first element larger than val (threshold)
    runner = anchor;
    while (runner->next != nullptr) {
        
        if (runner->next->data < val) {            
            // if the anchor is the first element, head of the whole linked list will be changed
            // insert the first < val (threshold) value as head
            if (anchorPrev == nullptr) {  
                *head = runner->next;
                anchorPrev = runner->next;
                runner->next = runner->next->next;
                anchorPrev->next = anchor;
            } else {                
                // else just simply plug-in other element less than val (threshold)
                anchorPrev->next = runner->next;
                runner->next = runner->next->next;
                anchorPrev->next->next = anchor;
                anchorPrev = anchorPrev->next;                
            }            
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
    partitionLinkedList(&head, value);

    printf("after partition: \n");
    head->printList();

    head->deallocateWholeLinkedList();
}