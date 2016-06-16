// Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water. 

// Note: You may not slant the container. 


class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = (int)height.size();
        if(n < 2) return 0;
        int i = 0, j = n - 1;
        int res = 0, cur = 0;
        while(i < j){
            cur= min(height[i], height[j]) * (j - i);
            res = res < cur ? cur : res;
            height[i] > height[j] ? j-- : i++;
        }
        return res;
    }
};