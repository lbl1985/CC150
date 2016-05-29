vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    vector<int> res;
    int sz1 = nums1.size();
    int sz2 = nums2.size();
    if(sz1 == 0 || sz2 == 0) return res;
    unordered_map<int, int> dict;
    for(int i = 0; i < sz1; i++){
        int t = nums1[i];
        if(dict.count(t)) {
            dict[t]++;
        } else {
            dict[t] = 1;
        }
    }
    for(int i = 0; i < sz2; i++) {
        int t = nums2[i];
        if(dict.count(t) && dict[t]) {
            res.push_back(t);
            dict[t]--;
        }
    }
    return res;
}