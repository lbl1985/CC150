// Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue. 

// Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively. 

// Note:
//  You are not suppose to use the library's sort function for this problem. 



class Solution {
public:
    void swap(int& a, int& b){
        int temp;
        temp = a; 
        a = b;
        b = temp;
    }
    void sortColors(vector<int>& nums) {
        int n = (int)nums.size();
        if(n == 0) return;
        int zeroIdx = 0;
        while(nums[zeroIdx] != 0 && zeroIdx < n){
            zeroIdx++;
        }
        int twoIdx = n - 1;
        while(nums[twoIdx] != 2 && twoIdx >= 0){
            twoIdx--;
        }
        for(int i = 0; i < n && zeroIdx < twoIdx; i++){
            if(nums[i] == 0){
                swap(nums[i], nums[zeroIdx++]);
                while(nums[zeroIdx] != 0 && zeroIdx < n && zeroIdx < twoIdx){
                    zeroIdx++;
                }
            }
            if(nums[i] == 2){
                swap(nums[i], nums[twoIdx--]);
                while(nums[twoIdx] != 2 && twoIdx >= 0 && zeroIdx < twoIdx){
                    twoIdx--;
                }
            }
        }
    }
};