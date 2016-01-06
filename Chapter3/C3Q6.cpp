// 3.6 Write a program to srot a stack in a ascending order. you may use additional stacks to
// hold items, but you may not copy the element6s into any other data structure (such 
// as an array). The stack supports the following operations: push, pop, peek, and isEmpty.

#include "..\inc\utils.h"
#include <stack>
#include <vector>

class stackSorter{
public:
    void sort(stack<int>* is) {
        if (is->empty()) {
            return;
        }
        while (!is->empty()) {
            if (buffer.empty()) {
                buffer.push(is->top());
                is->pop();
            }
            tmp = is->top();
            is->pop();
            while (!buffer.empty() && buffer.top() > tmp) {
                is->push(buffer.top());
                buffer.pop();
            }
            buffer.push(tmp);
        }
        // swap all elements from buffer (descend order) into is (ascend order)
        while (!buffer.empty()) {
            is->push(buffer.top());
            buffer.pop();
        }        
    }

private:
    stack<int> buffer;
    int tmp;
};

int C3Q6()
{
    stack<int> s0;
    stackSorter ss;
    int rnd;
    for (int i = 0; i < 10; i++) {
        rnd = generateRandomValue<int>(0, 10);
        printf("%d, ", rnd);
        s0.push(rnd);
    }

    printf("\n");

    ss.sort(&s0);

    while (!s0.empty()){
        printf("%d\n", s0.top());
        s0.pop();
    }

    return 0;
}