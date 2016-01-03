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

    int& top(int stackId)
    {
        // The stack is empty
        if (arrayPointer[stackId] != 0) {            
            return arr[arrayPointer[stackId]];
        }
    }


private: 
    int arr[arraySize];
    int arrayPointer[3];
    int arrayEndPointer[3];
};


int C3Q1()
{
    int arr[arraySize];
    memset(arr, 0, sizeof(int) * arraySize);
    int arrayPointer[3] = { 0, arraySize / 3, 2 * arraySize / 3};
    int arrayEndPoint[3] = { arraySize / 3 - 1, 2 * arraySize / 3 - 1, arraySize - 1};

    return 0;
}