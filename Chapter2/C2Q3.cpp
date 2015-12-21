// 2.3 Implement an algorithm to delete a node in the middle of a single 
// linked list, given only access to that node.
// EXAMPLE
// input: the node c from the linked list a -> b -> c -> d -> e
// result: nothing is returned, but the new linked list looks like a->b->d->e
// 
// This question is answered in-correct, I have not paid any attention to 
// "Given only access to that node"
// 

#include <iostream>
#include "..\utils.h"
#include "..\CLinkedList.h"
#include <time.h>
#include <stdlib.h>

#define SIZE 10
typedef unsigned int uint;
using namespace std;

void removeMiddleItem(Node<int>* head)
{
    Node<int>* slow = head;
    Node<int>* runner = head;
    Node<int>* slowAnchor = nullptr;
    while (runner->next != nullptr && runner->next->next != nullptr) {
        slowAnchor = slow;
        slow = slow->next;
        runner = runner->next->next;
    }

    slowAnchor->next = slow->next;
    cout << "remove item: " << slow->data << endl;
    delete slow;    
}

bool removeOneNode(Node<int>* n)
{
    if (n != nullptr && n->next != nullptr) {
        Node<int>* next = n->next;
        n->data = next->data;
        n->next = next->next;
        return true;
    } else {
        return false;
    }
}

int main()
{
    srand(uint(time(NULL)));

    Node<int>* head = new Node<int>(rand() % 10);
    for (int i = 0; i < SIZE; i++) {
        head->appendToTail(rand() % 10);
    }
    head->printList();

    //removeMiddleItem(head);

    printf("head->next->next is: %d\n", head->next->next->data);
    removeOneNode(head->next->next);
    head->printList();

    head->deallocateWholeLinkedList();
    return 0;
}