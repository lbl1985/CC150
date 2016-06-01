int numTrees(int n) {
    vector<int> res(n+1, 0);
    res[1] = 1;
    res[2] = 2;
    if (n >= 3) {
        for(int t = 3; t <= n; t++){
            res[t] += res[t-1] * 2;
            for(int i = 1; i < t; i++){
                res[t] += res[i - 1] * res[t- i];
            }
            
            // int delta = t / 2;
            // for(int i = 1; i <= delta; i++) {
            //     res[t] = res[t] + res[t - i] * 2;
            // }
            // if(t % 2 == 1){
            //     res[t] = res[t] + res[t - delta - 1] * res[t - delta - 1];
            // }
        }
    }
    
    return res[n];
}