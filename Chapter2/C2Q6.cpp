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

    while (fastRunner && fastRunner->next) {
        slowRunner = slowRunner->next;
        fastRunner = fastRunner->next->next;
        if (fastRunner == slowRunner) {
            break;
        }
    }

    if (fastRunner == nullptr || fastRunner->next == nullptr) {
        return nullptr;
    }

    slowRunner = head;
    while (slowRunner != fastRunner) {
        slowRunner = slowRunner->next;
        fastRunner = fastRunner->next;
    }

    return slowRunner;
}

int C2Q6()
{
    int arr[7] = { 3, 6, 9, 10, 8, 7, 6 };
    Node<int> *head = new Node<int>(arr, 7);
    Node<int> *runner = head;
    while (runner->next != nullptr) {
        runner = runner->next;
    }
    runner->next = head->next->next;
    
    const Node<int> *beginOfLoop = GetBeginOfLoop(head);
    std::cout << "The begin of the loop is: " << beginOfLoop->data << endl;
    return 0;
}