// Customered Linked List
// Author: Binlong Li 12/10/2015


#include <iostream>

using namespace std;

template <class T>
class Node
{
public:
    Node(int d)
    {
        data = d;
        next = nullptr;
    }

    void deallocateWholeLinkedList()
    {
        if (this->next == nullptr) {
            data = 0;
        } else {
            delete this->next;
        }
    }

    void appendToTail(T d)
    {
        Node* end = new Node(d);
        Node *n = this;
        while (n->next != nullptr) {
            n = n->next;
        }
        n->next = end;
    }

    size_t size()
    {
        size_t s = 0;
        Node* head = this;
        while (head) {
            s++;
            head = head->next;
        }
        return s;
    }

    // print out the list from the current node
    void printList()
    {
        cout << this->data << ", ";        
        const Node* n = this->next;
        while (n != nullptr) {
            cout << n->data << ", ";
            n = n->next;
        }
        printf("\n");
    }

    Node* next;
    T data;
};