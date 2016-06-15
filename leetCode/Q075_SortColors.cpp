// Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue. 

// Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively. 

// Note:
//  You are not suppose to use the library's sort function for this problem. 

class Solution {
public:

    void sortColors(vector<int>& nums) {
        int n = (int)nums.size();
        if(n == 0) return;
        int count[3] = {0, 0, 0};
        for(int i = 0; i < n; i++){
            count[nums[i]]++;
        }
        int c = 0;
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < count[i]; j++){
                nums[c++] = i;
            }
        }
    }
};