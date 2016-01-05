// 3.1 Describe how you could usa e single array to implement three stacks

#include "..\inc\utils.h"
#include <stack>
const int arraySize = 90;

class arrayStack{
public: 
    arrayStack()
    {
        memset(arr, 0, sizeof(int) * arraySize);
        arrayPointer[0] = 0; arrayPointer[1] = arraySize / 3; arrayPointer[2] = 2 * arraySize / 3;
        arrayEndPointer[0] = arraySize / 3; arrayEndPointer[1] = 2 * arraySize / 3 ; arrayEndPointer[2] = arraySize;
        arrayStartPointer[0] = 0; arrayStartPointer[1] = arraySize / 3; arrayStartPointer[2] = 2 * arraySize / 3;
    }

    void push(int stackId, int val)
    {
        if (arrayPointer[stackId] == arrayEndPointer[stackId]) {
            std::cout << "Stack " << stackId << " is Full;";            
        } else {
            arr[arrayPointer[stackId]++] = val;            
        }
    }

    void pop(int stackId)
    {
        if (arrayPointer[stackId] != 0) {            
            arr[arrayPointer[stackId]--] = 0;            
        }
    }

    bool empty(int stackId)
    {
        if (arrayPointer[stackId] == 0) {
            return true;
        } else {
            return false;
        }
    }

    int top(int stackId)
    {
        // The stack is empty
        if (arrayPointer[stackId] != arrayStartPointer[stackId]) {
            return arr[arrayPointer[stackId] - 1];
        } else {
            return -1;
        }
    }


private: 
    int arr[arraySize];
    int arrayPointer[3];
    int arrayEndPointer[3];
    int arrayStartPointer[3];
};


int C3Q1()
{
    arrayStack as;

    for (int i = 0; i < 30; i++) {
        as.push(0, i);        
        cout << "as stack 0 top is: " << as.top(0) << endl;
    }

    for (int i = 0; i < 3; i++) {
        as.pop(0);
        cout << "as stack 0 top is: " << as.top(0) << endl;
    }

    cout << "as stack 1 top is" << as.top(1) << endl;
    


    return 0;
}