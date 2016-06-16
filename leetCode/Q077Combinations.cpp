// Given two integers n and k, return all possible combinations of k numbers out of 1 ... n. 

// For example,
//  If n = 4 and k = 2, a solution is: 
// [
//   [2,4],
//   [3,4],
//   [2,3],
//   [1,2],
//   [1,3],
//   [1,4],
// ]

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        if (n < 1) return res;
        if (k == 1){
            for(int i= 1; i <= n; i++){
                res.push_back(vector<int>{i});
            }
            return res;
        }
        if(n == k){
            vector<int> tmp;
            for(int i = 1; i<= n; i++){
                tmp.push_back(i);
            }
            res.push_back(tmp);
            return res;
        }
        vector<vector<int>> withN = combine(n - 1, k - 1);
        vector<vector<int>> withOutN = combine(n - 1, k);
        for(int i= 0; i < withN.size(); i++){
            vector<int> tmp = withN[i];
            tmp.push_back(n);
            res.push_back(tmp);
        }
        for(int i= 0; i< withOutN.size(); i++){
            res.push_back(withOutN[i]);
        }
        return res;
    }
};