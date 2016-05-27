int coinchange(const vector<int>& coins, int amount)
{
    int dp[65535];
    int sz = (int)coins.size();
    memset(dp, 0x3f, sizeof(dp));
    dp[0] = 0;
    int j, k;
    for(int i = 0; i < sz; i++) {
        for(j = 0, k = coins[i]; k<= amount; j++, k++) {
            dp[k] = dp[j] + 1 < dp[k] ? dp[j] + 1 : dp[k];
        }    
    }
    
    return dp[amount];
}
int numSquares(int n) {
    int k = (int)sqrt(n);
    vector<int> coins;
    for(int i = 1; i <= k; i++){
        coins.push_back(i * i);
    }
    return coinchange(coins, n);
    
}