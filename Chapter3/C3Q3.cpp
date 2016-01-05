// 3.3 Imagine a (literal) stack of plates. If the stack gets too high, it might topple.
// Therefore, in rel life, we would likely start a new stack when the previous stack
// exceeds some threshold. Implement a data structure SetofStacks that mimics 
// this. SetOfStacks should be composed of serveral stacks and should create a
// new stack once the previoius one exceds capacity. SetOfStacks.push() and 
// SetOfStacks.pop() should behave identically to a single stack (that is, pop()
// should return the same values as it would if therer were just a single stack).
// FOLLOW UP
// Implement a function popat(int index) which perform a pop operation on
// a specific sub-stack
#include "..\inc\utils.h"
#include <stack>
#include <vector>

const int isDebug = true;

class SetOfStacks {
public:
    void push(int v)
    {
        if (vStacks.empty()) {
            stack<int> tmpStack;
            tmpStack.push(v);
            vStacks.push_back(tmpStack);
        } else {
            vector<stack<int>>::iterator itStack = vStacks.end() - 1;
            if (itStack->size() < stackLimit) {
                itStack->push(v);
            } else {
                stack<int> tmpStack;
                tmpStack.push(v);
                vStacks.push_back(tmpStack);
            }
        }
    }

    void pop()
    {
        if (!vStacks.empty()) {
            vector<stack<int>>::iterator itStack = vStacks.end() - 1;
            itStack->pop();
            // after pop if the stack is empty, remove the stack from vector
            if (itStack->empty()) {
                vStacks.erase(itStack);
            }
        }
    }

    int& top()
    {
        if (!vStacks.empty()) {
            vector<stack<int>>::iterator itStack = vStacks.end() - 1;
            return itStack->top();
        }
    }

    void popat(int stackIdx)
    {
        if (!vStacks.empty()) {
            if (vStacks.size() > (std::size_t)stackIdx) {
                vector<stack<int>>::iterator itStack = vStacks.begin() + stackIdx;
                itStack->pop();
                if (itStack->empty()) {
                    vStacks.erase(itStack);
                }
            }
        }
    }

    int& topat(int stackIdx)
    {
        if (!vStacks.empty()) {
            if (vStacks.size() > (std::size_t)stackIdx) {
                vector<stack<int>>::iterator itStack = vStacks.begin() + stackIdx;
                return itStack->top();
            }
        }
    }

    std::size_t size()
    {
        return vStacks.size();
    }

    bool empty()
    {
        return vStacks.empty();
    }

private:
    static const int stackLimit = 5;
    vector<stack<int>> vStacks;
};

int C3Q3()
{
    SetOfStacks sos;
    for (int i = 0; i < 30; i++) {
        sos.push(i);
        if (isDebug) {
            printf("vStack size is: %d, vStack top is %d\n", sos.size(), sos.top());
        }
    }

    printf("\n\n");
    for (int i = 0; i < 5; i++) {
        sos.popat(i);
        if (isDebug) {
            printf("vStack top at %d is %d\n", i, sos.topat(i));
        }
    }

    printf("\n\n");
    while (!sos.empty()) {
        if (isDebug) {
            printf("vStack top is %d\n", sos.top());
        }
        sos.pop();
    }
    return 0;
}