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

void bubbleSort2(vector<int>& arr)
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

void swap_leetCode(int& a, int&b){
	int temp;
	temp = a;
	a = b;
	b = temp;
}

int partition_leetCode(vector<int> &arr, size_t low, size_t high){
	int p = arr[high];
	size_t smallIndex = low;
	int tmp = 0;
	for(size_t i = low; i < high; i++){
		if(arr[i] <= p){
			swap(arr[i], arr[smallIndex]);			
			smallIndex++;
		}		
	}

	swap(arr[smallIndex], arr[high]);	
	return smallIndex;
}

void quicksort_leetCode(vector<int> &arr, int low, int high){
	if(low < high){
		int middle = partition_leetCode(arr, low, high);
		quicksort_leetCode(arr, low, middle - 1);
		quicksort_leetCode(arr, middle + 1, high);
	}
}



void wiggleSort(vector<int>& num) {
	quicksort_leetCode(num, 0, num.size()-1);
	size_t sz = num.size();
	int halfSize = ((int)sz + 1) >> 1;
	int offset = sz % 2 == 0 ? halfSize : halfSize + 1;
	// int highIndex = halfSize + 1;
	for (int lowIndex = 1, highIndex = halfSize + 1; lowIndex < halfSize && highIndex < (int)sz; lowIndex += 2){
		swap_leetCode(num[lowIndex], num[highIndex]);
		highIndex += 2;
	}
}

void printVector(const vector<int> &v) {
	for (size_t i = 0; i < v.size(); i++) {
		printf("%d ", v[i]);
	}
}

int Q324_WiggleSortII()
{
	vector<vector<int> > tests{ { 1, 5, 1, 1, 6, 4 }, { 1, 3, 2, 2, 3, 1} , {1, 3, 2, 2, 3}};
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