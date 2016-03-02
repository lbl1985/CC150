// Given an array of integers, return indices of the two numbers such that they add up to a specific target.
// 
// You may assume that each input would have exactly one solution.
// 
// Example:
// 
// Given nums = [2, 7, 11, 15], target = 9,
// 
// Because nums[0] + nums[1] = 2 + 7 = 9,
// return [0, 1].
// 
// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
        
//     }
// };
// 
// UPDATE (2016/2/13):
//  The return format had been changed to zero-based indices. Please read the above updated description carefully. 
// Author: Binlong Li
// Date: 02/26/2016
// Finish: 02/27/2016

#include "..\inc\utils.h"

#include <iostream>
#include <vector> 
using namespace std;

vector<int> twoSum(vector<int>& nums, int target)
{
	vector<int> res;
	vector<int> search;
	size_t len = nums.size();
	for(size_t i = 0; i < len; i++ ){
		int num = nums[i];
		for(size_t j = 0; j < search.size(); j++){
			if(num == search[j]){
				res.push_back(i);
				res.push_back(j);
				return res;
			}
		}
		search.push_back(target - num);
	}
	return res;
}

int Q001_TwoSum(){
	int example1[4] = {2, 7, 11, 15};
	int target = 9;
	vector<int> nums(example1, example1 + 3);
	vector<int> res = twoSum(nums, target);
	printf("%d = %d + %d\n", target, nums[res[0]], nums[res[1]]);
	return 0;
}

