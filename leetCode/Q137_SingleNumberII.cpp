int singleNumber(vector<int>& nums) {
    int res = 0;
    int n = (int)nums.size();
    for(int i = 0; i < 32; i++) {
        int tmp = 1 << i;
        int cnt = 0;
        for(int j = 0; j < n; j++) {
            cnt += bool(nums[j] & tmp);
        }
        if(cnt % 3){
            res |= tmp;
        }
    }
    return res;
}