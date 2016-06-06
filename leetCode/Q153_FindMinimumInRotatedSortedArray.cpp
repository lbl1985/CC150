// Suppose a sorted array is rotated at some pivot unknown to you beforehand.

// (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

// Find the minimum element.

// You may assume no duplicate exists in the array.

class Solution {
public:
    int findMinHelper(vector<int>& nums, int left, int right)
    {
        if(left >= right) {
            return nums[left];
        }
        if(nums[left] < nums[right]) return nums[left];
        int mid = (left + right) / 2;
        return min(findMinHelper(nums, left, mid), findMinHelper(nums, mid + 1, right));
        
    }
    int findMin(vector<int>& nums) {
        int n = (int)nums.size();
        if(n == 1) return nums[0];
        if(nums[0] < nums[n - 1]) return nums[0];
        return findMinHelper(nums, 0, n - 1);
    }
};