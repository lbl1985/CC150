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
// Today I should be able to fix this issue and proceed to another 2 questions.

#include "..\utils.h"

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
    int aNum = linkedListToNumAscOrder<int>(a);
    int bNum = linkedListToNumAscOrder<int>(b);

    return aNum + bNum;
}

// This is a linked list solution
Node<int>* AddTwoLinkedList(Node<int>* a, Node<int>* b)
{
    if (nullptr == a && nullptr == b) {
        return nullptr;
    }
    if (nullptr == a) {
        return b;
    }
    if (nullptr == b) {
        return a;
    }
    Node<int>* runnerA = a;
    Node<int>* runnerB = b;
    // initial the res head node as 0, 
    Node<int>* res = new Node<int>(0);    
    bool initial = true;

    int additional = 0;
    while (runnerA != nullptr && runnerB != nullptr) {
        int temp = runnerA->data + runnerB->data;             
        if (initial) {
            res->data = temp % 10;
            initial = false;
        } else {
            res->appendToTail(temp % 10 + additional); 
            additional = 0;
        }        
        additional = temp / 10;
        runnerA = runnerA->next;
        runnerB = runnerB->next;
    }

    if (nullptr == runnerA) {
        while (runnerB != nullptr) {
            res->appendToTail(runnerB->data + additional);
            additional = 0;
            runnerB = runnerB->next;
        }
    }

    if (nullptr == runnerB) {
        while (runnerA != nullptr) {
            res->appendToTail(runnerA->data + additional);
            additional = 0;
            runnerA = runnerA->next;
        }
    }

    return res;
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

    printf("Used number: \n");
    cout << linkedListToNumAscOrder<int>(a) << " + " << linkedListToNumAscOrder<int>(b) << " = " << linkedListToNumAscOrder<int>(c) << endl;
    
    Node<int> *d = AddTwoLinkedList(a, b);
    printf("Used linked list: \n");
    cout << linkedListToNumAscOrder<int>(a) << " + " << linkedListToNumAscOrder<int>(b) << " = " << linkedListToNumAscOrder<int>(d) << endl;

    a->deallocateWholeLinkedList();
    b->deallocateWholeLinkedList();
    c->deallocateWholeLinkedList();
    d->deallocateWholeLinkedList();
}
