// Given an unsorted array nums, reorder it such that nums[0] < nums[1] > nums[2] < nums[3].... 
// 
// Example:
//  (1) Given nums = [1, 5, 1, 1, 6, 4], one possible answer is [1, 4, 1, 5, 1, 6]. 
//  (2) Given nums = [1, 3, 2, 2, 3, 1], one possible answer is [2, 3, 1, 3, 1, 2]. 
// 
// Note:
//  You may assume all input has valid answer. 
// 
// Follow Up:
//  Can you do it in O(n) time and/or in-place with O(1) extra space? 
// class Solution {
// public:
//     void wiggleSort(vector<int>& nums) {
//         
//     }
// };

#include "..\inc\utils.h"
#include <vector>

void bubbleSort(vector<int>& arr)
{
	int sz = (int)arr.size();
	int temp;
	for (int endIndex = sz - 1; endIndex > 0; endIndex--) {
		for (int i = 0; i < endIndex; i++) {
			if (arr[i] > arr[i + 1]) {
				temp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = temp;
			}
		}
	}
}

void wiggleSort(vector<int>& num) {
	bubbleSort(num);
	size_t sz = num.size();
	int halfSize = sz / 2;
	int offset = sz % 2 == 0 ? halfSize : halfSize + 1;

	vector<int> numSorted(num);
	int index = 0;
	for (int i = 0; i < halfSize; i++) {
		num[index++] = numSorted[i];
		num[index++] = numSorted[i + offset];
	}
	if (index < sz - 1) {
		num[index++] = numSorted[halfSize];
	}
}

void printVector(const vector<int> &v) {
	for (size_t i = 0; i < v.size(); i++) {
		printf("%d ", v[i]);
	}
}

int Q324_WiggleSortII()
{
	vector<vector<int> > tests{ { 1, 5, 1, 1, 6, 4 }, { 1, 3, 2, 2, 3, 1} };
	for (size_t i = 0; i < tests.size(); i++) {
		printf("test set %d: \n", i);
		printVector(tests[i]);
		wiggleSort(tests[i]);
		printf("after wiggle sort: \n");
		printVector(tests[i]);
		printf("\n");
	}
	
	return 0;
}