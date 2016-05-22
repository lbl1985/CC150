// Given an unsorted array return whether an increasing subsequence of length 3 exists or not in the array. 

// Formally the function should:


// Return true if there exists i, j, k  
//  such that arr[i] < arr[j] < arr[k] given 0 ≤ i < j < k ≤ n-1 else return false. 


// Your algorithm should run in O(n) time complexity and O(1) space complexity. 

// Examples:
//  Given [1, 2, 3, 4, 5],
//  return true. 

// Given [5, 4, 3, 2, 1],
//  return false. 

// bool increasingTriplet(vector<int>& nums) {
        
//     }
// Author: Binlong Li
// Date:   05/21/2016
// Finish: 05/21/2016


#include "..\inc\utils.h"
#include <vector>
#include <climits>
using namespace std;

bool increasingTriplet(std::vector<int>& nums)
{
	int sz = (int) nums.size();
	if(sz < 3) {
		return false;
	}
	int small[2] = {INT_MAX, INT_MAX};
	int threshold = INT_MAX;
	for(int i = 0; i < sz; i++) {
		int cur = nums[i];
		if(cur > threshold) {
			return true;
		}
		if(cur < small[0]) {
			small[0] = cur;
			small[1] = INT_MAX;
			continue;
		} else if ( cur > small[0] && cur < small[1]) {
			small[1] = cur;
			if (cur < threshold) {
				threshold = cur;
			}
			continue;
		} else if (cur > small[0] && cur > small[1]){
			return true;
		}
	}
	return false;
}

int Q334_Increasing_Triplet_Subsequence()
{
	printf("inside of Q334_Increasing_Triplet_Subsequence\n");
	vector<int> test1{1, 2, 3, 4, 5};
	printf("test1 [1, 2, 3, 4, 5], expect true, result: %s\n", JUDGE_RESULT(increasingTriplet, test1));
	vector<int> test2{5, 4, 3, 2, 5};
	printf("test2 [5, 4, 3, 2, 1], expect false, result: %s\n", JUDGE_RESULT(increasingTriplet, test2));
	vector<int> test3{0, 4, 2, 1, 0, -1, -3};
	printf("test3 [0, 4, 2, 1, 0, -1, -3] expect false, result: %s\n", JUDGE_RESULT(increasingTriplet, test3));
	vector<int> test4{5, 1, 5, 5, 2, 5, 4};
	printf("test4 [5, 1, 5, 5, 2, 5 4] expect true, result: %s\n", JUDGE_RESULT(increasingTriplet, test4));
	vector<int> test5{1, 1,1,1,1,1,1};
	printf("test5 [1, 1,1, 1,1,1,1] expect false, resutl: %s\n", JUDGE_RESULT(increasingTriplet, test5));
	vector<int> test6{1,0,0,1};
	printf("test6 [1, 0, 0, 1] expect false, result: %s\n", JUDGE_RESULT(increasingTriplet, test6));
	vector<int> test7{1, 0, 0, 2, 0, 0, -1, -1, 3};
	printf("test7 [1, 0, 0, 2, 0 , 0, -1, -1, 3] expect true, result: %s\n", JUDGE_RESULT(increasingTriplet, test7));

	return 0;
}