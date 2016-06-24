// Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element. 

// For example,
//  Given [3,2,1,5,6,4] and k = 2, return 5. 

// Note: 
//  You may assume k is always valid, 1 ≤ k ≤ array's length.


class Solution {
public:

    int quicksort(vector<int>& nums, int k, int left, int right) {
        int index = partition(nums, left, right);
        if(index == n - k) {
            return nums[index];
        }
        
        if(index > n - k) {
            if (left < index - 1) {
                return quicksort(nums, k, left, index - 1);
            } else {
                return nums[left];
            }
        } else {
            if(index < right) {
                return quicksort(nums, k, index, right);
            } else {
                return nums[right];
            }
        }
    }
    
    int partition(vector<int>& nums, int left, int right) {
        int pivot = nums[(left + right) / 2];
        while(left <= right){
            while(nums[left] < pivot) left++;
            while(nums[right] > pivot) right--;
            if(left <= right){
                swap(nums[left], nums[right]);
                left++;
                right--;
            }
        }
        return left;
    }

    int findKthLargest(vector<int>& nums, int k) {
        n = nums.size();
        return quicksort(nums, k, 0, n - 1);
    }
private:
    int n;
};