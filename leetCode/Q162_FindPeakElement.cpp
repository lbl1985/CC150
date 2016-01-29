// Q162. Find Peak Element
// A peak element is an element that is greater than its neighbors.
// Given an input array where num[i] ≠ num[i+1], find a peak element and return its index.
// The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.
// You may imagine that num[-1] = num[n] = -∞.
// For example, in array [1, 2, 3, 1], 3 is a peak element and your function should return the index number 2.
// class Solution {
// public:
//     int findPeakElement(vector<int>& nums) {
//         
//     }
// };

#include "..\inc\utils.h"
#include <vector>
#include <climits>

using namespace std;

int findPeakElement(vector<int>& nums){	
	if(nums.size() == 1){
		return 0;
	} else if(nums.size() == 2){
		return nums[0] > nums[1] ? 0 : 1;		
	} else{
		int s = (int)nums.size();
		// special care for i = 0;
		if(nums[0] > nums[1]){
			return 0;
		}
		int prev = nums[0];
		int next = nums[2];
		for(int i = 1; i < s - 1; i++ ){
			
			if(nums[i] > nums[i - 1] && nums[i] > nums[i+1])	{
				return i;
			}
		}
		// special care for i = s - 1;
		if(nums[s-1] > nums[s-2]){
			return s - 1;
		}
		return -1;
	}
}


int Q162_FindPeakElement(){
	cout << endl << "internal Q162_FindPeakElement" << endl;
	vector<int> arr{1, 2, 3, 1};
	cout << "The peak element index is: " << findPeakElement(arr);
	 
	return 0;
}