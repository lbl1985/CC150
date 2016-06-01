int searchInsert(vector<int>& nums, int target) {
    int n = (int)nums.size();
    if(n == 0) return 0;
    if(nums[n - 1] < target) return n;
    int res = 0;
    for(int i = 0; i < n; i++){
        if(nums[i] == target) {
            return i;
        } else if(nums[i] > target) {
            return i;
        } else {
            res = i;
        }
    }
    return res;
}