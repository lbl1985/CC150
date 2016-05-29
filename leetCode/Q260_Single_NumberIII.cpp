vector<int> singleNumber(vector<int>& nums) {
    int sz = (int)nums.size();
    int res1 = 0, res2 = 0;
    int x = 0;
    vector<int> res;
    for(int i = 0; i < sz; i++) {
        x ^= nums[i];
    }
    
    int lastbit = x - (x & (x - 1));
    
    for(int i = 0; i < sz; i++) {
        if((nums[i] & lastbit) == 0) {
            res1 ^= nums[i];
        } else {
            res2 ^= nums[i];
        }
    }
    
    res.push_back(res1);
    res.push_back(res2);
    return res;
}