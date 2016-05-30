int maxProfit(vector<int>& prices) {
    int low = INT_MAX, high = INT_MIN, diff = 0, t;
    int sz = prices.size();
    if (sz == 0 || sz == 1) return 0;
    for(int i = 0; i < sz; i++) {
        t = prices[i];
        if(t < low) {
            low = t; high = t;
        } else if(t > high) {
            diff = (t - low) > diff ? (t - low) : diff ;
            high = t;
        }
    }
    return diff;
}