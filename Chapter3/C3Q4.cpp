// 3.4 In the classic problem of the Towers of Hanoi, you have 3 towers and N disks of
// different sizes which can slide onto any tower. The puzzle starts with disks sorted 
// in ascending order of size from top to bottom (i.e., each disk sits on top of an even 
// larger one). You have the following constraints:
// (1) Only one disk can be moved at a time.
// (2) A disk is slid off the top of one tower onto the next rod.
// (3) A disk can only be placed on top of a larger disk.

#include "..\inc\utils.h"
#include <stack>
#include <vector>

using namespace std;

class Tower{
public:
    Tower(int index):id(index) { }

    void add(int v)
    {
        if (!stk.empty() && v >= stk.top()) {
            printf(" %d could not add to stack %d, stack %d top is %d\n", v, id, id, stk.top());
        }
        stk.push(v);
    }

    void moveTop(Tower* dst)
    {
        if (!stk.empty()) {
            printf("Move %d from Tower %d to Tower %d\n", stk.top(), id, dst->getId());
            dst->add(stk.top());
            stk.pop();
        }        
    }

    void moveDisks(int iDiskNum, Tower* dst, Tower* buffer)
    {
        if (iDiskNum >= 1) {
            moveDisks(iDiskNum - 1, buffer, dst);
            moveTop(dst);
            buffer->moveDisks(iDiskNum - 1, dst, this);
        }
    }
    
    const int getId() const
    {
        return id;
    }
private:
    stack<int> stk;
    const int id;
};


int C3Q4()
{
    vector<Tower> vTower;
    for (int i = 0; i < 3; i++) {
        Tower tmpTower(i);
        vTower.push_back(tmpTower);
    }

    for (int i = 5; i > 0; i--) {
        vTower[0].add(i);
    }

    vTower[0].moveDisks(5, &vTower[2], &vTower[1]);
    
    return 0;
}