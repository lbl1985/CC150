int maxProduct(vector<string>& words) {
    int n = (int)words.size();
    if(n == 0 || n == 1) return 0;
    
    vector<int> feature(n, 0);
    vector<int> sz(n, 0);
    for(int i = 0; i < n; i++){
        string tmpStr = words[i];
        sz[i] = (int)tmpStr.size();
        int t = 0;
        for(int j = 0; j < sz[i]; j++) {
            t |= (1 << (tmpStr[j] - 'a'));
        }
        feature[i] = t;
    }
    
    int res = 0;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if( (feature[i] & feature[j]) == 0) {
                res = sz[i] * sz[j] > res ? sz[i] * sz[j] : res;
            }
        }
    }
    return res;
}