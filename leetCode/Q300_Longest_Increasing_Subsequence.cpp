// This is the O(n^2) solution
int lengthOfLIS(vector<int>& nums) {
    int sz = (int)nums.size();
    if(sz == 0 || sz == 1) return sz;
    vector<int> dist(sz, 1);
    int max = 0;
    for(int i = 0; i < sz; i++) {
        for(int j = 0; j < i; j++) {
            if(nums[j] < nums[i] && dist[i] < dist[j] + 1) {
                dist[i] = dist[j] + 1;
            }
        }
        max = dist[i] > max ? dist[i] : max;
    }
    return max;
}