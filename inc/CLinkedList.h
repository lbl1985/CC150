// Customered Linked List
// Author: Binlong Li 12/10/2015


#include <iostream>

using namespace std;

template <class T>
class Node
{
public:
    Node(T d)
    {
        data = d;
        next = nullptr;
        s = 1;
    }

    Node(T* arr, std::size_t size)
    {
        if (arr != nullptr) {
            data = arr[0];
            next = nullptr;
            s = 1;
            for (size_t i = 1; i < size; i++) {
                this->appendToTail(arr[i]);                
            }
        }
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
        s++;
    }

    size_t size() const
    {
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

    const T& operator[](std::size_t idx) const
    {
        const Node* head = this;
        while (idx-- && head) {
            head = head->next;
        }
        return head->data;
    }

    T& operator[](std::size_t idx)
    {
        Node* head = this;
        while (idx-- && head) {
            head = head->next;
        }
        return head->data;
    }

    Node* next;
    T data;
    size_t s;
};