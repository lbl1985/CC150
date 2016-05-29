vector<int> productExceptSelf(vector<int>& nums) {
    int sz = (int)nums.size(), tmp;
    vector<int> res(sz, 1);
    for(int i = 1; i < sz; i++) {
        res[i] = res[i - 1] * nums[i - 1];
    }
    int t = nums[sz - 1];
    for(int i = sz - 2; i >= 0; i--) {
        res[i] = res[i] * t;
        t *= nums[i];
    }
    return res;
}