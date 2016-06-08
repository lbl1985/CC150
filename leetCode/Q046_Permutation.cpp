// Given a collection of distinct numbers, return all possible permutations. 

// For example,
// [1,2,3] have the following permutations:

// [
//   [1,2,3],
//   [1,3,2],
//   [2,1,3],
//   [2,3,1],
//   [3,1,2],
//   [3,2,1]
// ]



class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> t;
        int sz = (int)nums.size();
        if(sz == 0) return res;
        if(sz == 1) {
            t.push_back(nums[0]);
            res.push_back(t);
            return res;
        }
        
        for(int i = 0; i < sz; i++) {
            int cur = nums[i];
            vector<int> tnums(nums);
            tnums.erase(tnums.begin() + i);
            vector<vector<int>> tres = permute(tnums);
            for(int j = 0; j < tres.size(); j++){
                tres[j].insert(tres[j].begin(), cur);
                res.push_back(tres[j]);
            }
        }
        return res;
    }
};