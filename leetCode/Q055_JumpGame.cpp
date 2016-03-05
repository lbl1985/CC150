// Given an array of non-negative integers, you are initially positioned at the first index of the array. 

// Each element in the array represents your maximum jump length at that position. 

// Determine if you are able to reach the last index. 

// For example:
//  A = [2,3,1,1,4], return true. 

// A = [3,2,1,0,4], return false. 

// class Solution {
// public:
//     bool canJump(vector<int>& nums) {
//         
//     }
// };
// Author: Binlong Li
// Date:   03/03/2016

#include "..\inc\utils.h"
#include <vector>

class Solution {
public:
    bool canJump(vector<int>& nums) {
        
    }
};

int Q055_JumpGame()
{
	printf("Q055_JumpGame\n");
	int ex1[] = {2, 3, 1, 1, 4};
	int ex2[] = {3, 2, 1, 0, 4};

	vector<vector<int>> test;
	vector<int> tmp1(ex1, ex1 + 5);
	test.push_back(tmp1);
	vector<int> tmp2(ex2, ex2 + 5);
	test.push_back(tmp2);

	for(size_t i = 0; i < test.size(); i++){
		printVector<int>(test[i]);
	}

	return 0;
}