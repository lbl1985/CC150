// 2.6 Given a circular linked list, implement an algorithm which returns the node at the beginning of the loop.
// DEFINITION
// Circular linked list: A (corrupt) linked list in which a node's next pointer points to an earlier node,
// so as to make a loop in the linked list.
// EXAMPLE
// Input: A -> B -> C -> D -> E -> C [the same C as earlier]
// Output: C

#include "..\inc\utils.h"


const Node<int>* GetBeginOfLoop(const Node<int>* head)
{
    if (nullptr == head) {
        return nullptr;
    }

    Node<int> const *fastRunner = head, *slowRunner = head;

    if (fastRunner->next != nullptr) {
        fastRunner = fastRunner->next->next;
    }

    while (fastRunner->next && fastRunner->next->next && fastRunner != slowRunner) {
        slowRunner = slowRunner->next;
        fastRunner = fastRunner->next->next;
    }
    return slowRunner;
}

int C2Q6()
{
    int arr[6] = { 3, 6, 9, 10, 8, 7 };
    Node<int> *head = new Node<int>(arr, 6);
    Node<int> *runner = head;
    while (runner->next != nullptr) {
        runner = runner->next;
    }
    runner->next = head->next->next;
    
    const Node<int> *beginOfLoop = GetBeginOfLoop(head);
    std::cout << "The begin of the loop is: " << beginOfLoop->data << endl;
    return 0;
}