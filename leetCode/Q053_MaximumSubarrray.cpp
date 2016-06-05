// [1]
// [-2, 1, -3, 4, -1, 2, 1, -5, 4]
// [-2, -1]

// Find the contiguous subarray within an array (containing at least one number) which has the largest sum. 

// For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
//  the contiguous subarray [4,−1,2,1] has the largest sum = 6. 

// click to show more practice.

// More practice: 
// If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.


int maxSubArray(vector<int>& nums) {
        int n = (int)nums.size();
        if(n == 0) return 0;
        if(n == 1) return nums[0];
        int sum = 0;
        int max = INT_MIN;
        for(int i = 0; i < n; i++){
            sum += nums[i];
            max = sum > max ? sum : max;
            if(sum < 0){
                sum = 0;
            } 
            
            
        }
        return max;
    }