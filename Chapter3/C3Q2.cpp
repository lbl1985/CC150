// How would you design a stack which, in addition to push and pop, also has a function min
// which return sthe minimum element? Push, pop and min should all operate in O(1) time
#include "..\inc\utils.h"
#include <stack>
#include <vector>

class minStack{
public:
    void push(int val)
    {
        if (mainS.empty()) {            
            mainS.push(val);
            minValueS.push(val);
        } else {
            if (val <= minValueS.top()) {
                minValueS.push(val);
            }
            mainS.push(val);
        }
    }

    void pop()
    {
        if (!mainS.empty()) {
            int val = mainS.top();
            if (val == minValueS.top()) {
                minValueS.pop();
            }
            mainS.pop();
        }
    }

    int min()
    {
        return minValueS.top();
    }

private:
    stack<int> mainS;
    stack<int> minValueS;
};

int C3Q2()
{
    minStack ms;
    vector<int> arr = { 7, 8, 4, 9, 10, 3,  8, 6 };
    for (size_t i = 0; i < arr.size(); i++) {
        ms.push(arr[i]);
        cout << " ms min value is: " << ms.min() << endl;
    }

    for (size_t i = 0; i < arr.size(); i++) {
        cout << "ms min value is: " << ms.min() << endl;
        ms.pop();
    }

    return 0;
}