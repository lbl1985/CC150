vector<int> combinationSum3Helper(int k, int n, int start){
    vector<int> res;
    int sum_low = 0;
    int sum_high = 0;
    for(int i = 0; i < k; i ++){
        sum_low += start + i;
        sum_high += 9 - i;
    }
    if(sum_low > n || sum_high < n){
        return res;
    }
    if (k == 1) {
        res.push_back(n);
        return res;
    }
    
    vector<int> t = combinationSum3Helper(k - 1, n - start, start + 1);
    
    if(t.size() == 0){
        return res;
    } else {
        res.insert(res.begin(), start);
        return res;
    }
}

vector<vector<int>> csHelper(int k, int n, int start)
{
    vector<vector<int>> res;
    vector<int> t;
    for(int i = start; i <= 9; i++){
        t.clear();
        for(int j = i + 1; j < 9; j++) {
            t.push_back(start);
            vector<int> it = combinationSum3Helper(k - 1, n - i, i + 1);
            if(it.size() == 0) {
                break;
            } else {
                for(int k = 0; k < t.size(); k++) {
                    t.push_back(it[k]);
                }
                res.push_back(t);
                t.clear();
            }
        }
    }
    return res;
}
vector<vector<int>> combinationSum3(int k, int n) {
    return csHelper(k, n, 1);
}