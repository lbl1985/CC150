int missingNumber(vector<int>& nums) {
        int sz = (int) nums.size();
        int targetNum = sz * (sz + 1) / 2;
        int sum = 0;
        for (int i = 0; i < sz; i++){
            sum += nums[i];
        }
        return targetNum - sum;
    }