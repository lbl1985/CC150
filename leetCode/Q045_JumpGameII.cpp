// Given an array of non-negative integers, you are initially positioned at the first index of the array. 
// 
// Each element in the array represents your maximum jump length at that position. 
// 
// Your goal is to reach the last index in the minimum number of jumps. 
// 
// For example:
//  Given array A = [2,3,1,1,4] 
// 
// The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.) 
// 
// Note:
//  You can assume that you can always reach the last index.
// 
// class Solution {
// public:
//     int jump(vector<int>& nums) {
//         
//     }
// };
// 
// Author: Binlong Li
// Date:  03/03/2016

#include "..\inc\utils.h"

#include <vector>
using namespace std;

int jump(vector<int>& nums)
{
	size_t sz = nums.size();
	if(sz <= 1){
		return 0;
	}
	vector<int> idxQueue;

	bool reach = false;		
	int curIdx =0;	

	while(!reach){
		idxQueue.push_back(curIdx);
		int maxV = -1;
		int maxIdx = -1;
		for(int i = 0; i < nums[curIdx]; i++){
			int curV = nums[curIdx + i + 1];
			if(curV > maxV){
				maxV = curV;
				maxIdx = curIdx + i + 1;
			}
		}
		if(maxIdx + maxV >= (int)(sz - 1)){
			idxQueue.push_back(maxIdx);
			reach = true;
		} else {
			curIdx = maxIdx;
		}
	}	
	
	cout << "Need " << idxQueue.size() << " steps: " << endl;
	printVector<int>(idxQueue);
	cout << endl;
	return (int)idxQueue.size();
}

int Q045_JumpGameII()
{
	printf("inside of Q045_JumpGameII\n");
	vector<int> exp1{2, 3, 1, 1, 4};
	vector<int> exp2{0};

	cout << "test case 1: " << endl;
	printVector<int>(exp1);
	jump(exp1);

	cout << "test case 2: " << endl;
	printVector<int>(exp2);
	jump(exp2);

	return 0;
}