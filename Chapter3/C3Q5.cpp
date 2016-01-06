// 3.5 Implement a MyQueue class which implements a queue using two stacks

#include "..\inc\utils.h"
#include <stack>

enum mode{
    fromPushToPull = 0,
    fromPullToPush
};

class MyQueue{
public:

    MyQueue():pullTopValue(0) {}

    void push(int v)
    {
        if (!pullStack.empty()) {
            swapStack(&pullStack, &pushStack);
        }
        pushStack.push(v);
    }

    int pull()
    {
        if (pullStack.empty() && !pushStack.empty()) {
            swapStack(&pushStack, &pullStack);
            pullTopValue = pullStack.top();
            pullStack.pop();
            return pullTopValue;
        } else if (!pullStack.empty()){
            pullTopValue = pullStack.top();
            pullStack.pop();
            return pullTopValue;
        }
        return S_Invalid;
    }

    void swapStack(stack<int>* src, stack<int>* dst)
    {
        while (!src->empty()) {
            dst->push(src->top());
            src->pop();
        }
    }

private:
    stack<int> pushStack;
    stack<int> pullStack;
    int pullTopValue;
};


int C3Q5()
{
    MyQueue mq;
    int pushArray[3] = { 10, 6, 3 };
    int pullArray[3] = { 8, 4, 7 };

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < pushArray[i]; j++) {
            mq.push(j);
            //printf("push %d into queue", j);
        }

        for (int j = 0; j < pullArray[i]; j++) {
            printf("pull %d out\n", mq.pull());
        }
    }
    
    return 0;
}