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

class SetOfStacks
{
public:
    void push(int v)
    {
        if (vStacks.empty()) {
            stack<int> tmpStack; 
            tmpStack.push(v);
            vStacks.push_back(tmpStack);

            vStacks.push_back(tmpStack);
        } else {
            vector<stack<int>>::iterator itStack = vStacks.end();
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
            vector<stack<int>>::iterator itStack = vStacks.end();
            if (!itStack->empty()) {
                itStack->pop();
            } else {
                vStacks.erase(itStack);
                this->pop();
            }
        }
    }
private:
    static const int stackLimit = 30;
    vector<stack<int>> vStacks;
};

int C3Q3()
{
    
    return 0;
}