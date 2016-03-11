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
// Solved: 03/10/2016

#include "..\inc\utils.h"

#include <vector>
using namespace std;
#define DEBUG 1

int jump(vector<int>& nums)
{
	size_t sz = nums.size();
	if(sz <= 1){
		return 0;
	}	
	int step = 0;
	int curIdx =0;	

	while(true){
		step++;
		int maxV = -1;
		int maxIdx = -1;
		int curStep = nums[curIdx];
		for(int i = curStep; i > 0; i--){
			if(curIdx + i >= (int)(sz - 1)){
				return step;
			}
			int curV = nums[curIdx + i] + curIdx + i;
			if(curV >= (int)(sz-1)){
				return ++step;
			}
			if(curV > maxV){
				maxV = curV;
				maxIdx = curIdx + i;
			}
		}
		curIdx = maxIdx;
	}	
	return step;
}

int Q045_JumpGameII()
{
	printf("inside of Q045_JumpGameII\n");
	vector<int> exp1{2, 3, 1, 1, 4};
	vector<int> exp2{0};
	vector<int> exp3{1, 2};

	cout << "test case 1: " << endl;
	printVector<int>(exp1);
	cout << "Need " << jump(exp1) << " steps" << endl << endl;

	cout << "test case 2: " << endl;
	printVector<int>(exp2);
	cout << "Need " << jump(exp2) << " steps" << endl << endl;

	cout << "test case 3:" << endl;
	printVector<int>(exp3);
	cout << "Need " << jump(exp3) << " steps" << endl << endl;
	return 0;
}