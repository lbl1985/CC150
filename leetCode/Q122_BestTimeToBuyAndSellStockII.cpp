int maxProfit(vector<int>& prices) {
    int n = (int)prices.size();
    if(n == 0 || n == 1)  return 0;
    int res = 0;
    int seg = 0;
    int low;
    bool isUp = false;
    for(int i = 1; i < n; i++) {
        if(prices[i] - prices[i - 1] > 0) {
            seg += prices[i] - prices[i - 1];
            isUp = true;
        } else {
            res += seg;
            low = prices[i];
            seg = 0;
            isUp = false;
        }
    }
    if (isUp) {
        res += seg;
    }
    return res;
}