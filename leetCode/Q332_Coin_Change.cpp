// You are given coins of different denominations and a total amount of money amount. Write a function to compute the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1. 

// Example 1:
//  coins = [1, 2, 5], amount = 11
//  return 3 (11 = 5 + 5 + 1) 

// Example 2:
//  coins = [2], amount = 3
//  return -1. 

// Note:
//  You may assume that you have an infinite number of each kind of coin. 

// int coinChange(vector<int>& coins, int amount) {
        
// }
// Author: Binlong Li
// Date: 05/23/2016
// Finish: 05/24/2016

#include "..\inc\utils.h"
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int coinChange(vector<int>& coins, int amount) {
	int dp[65535];
	memset(dp, 0x7f, sizeof(dp));
	int j, k;
	dp[0] = 0;
	int sz = (int)coins.size();
	for(int i = 0; i < sz; i++) {
		for(j = 0, k = coins[i]; k <= amount; j++, k++) {
			dp[k] = dp[j] + 1 < dp[k] ? dp[j] + 1 : dp[k];
		}
	}
	return dp[amount] == 0x7f7f7f7f ? -1 : dp[amount];
}

int dp[65535];
int coinChange(vector<int>& coins, int coinsSize, int amount) {
	memset(dp, 0x3f, sizeof(dp));
	dp[0] = 0;
	for (int i = 0; i < coinsSize; i++)
		for (int j = 0, k = coins[i]; k <= amount; j++, k++)
			dp[k] = dp[j] + 1 < dp[k] ? dp[j] + 1 : dp[k];
	return dp[amount] == 0x3f3f3f3f ? -1 : dp[amount];
}


int Q332_Coin_Change()
{
	printf("inside of Q332_Coin_Change\n");
	cout << "test 1" << endl;
	vector<int> test1{5, 1, 2};
	int res1 = coinChange(test1, 11);
	printVector(test1); cout << ", 11" << endl;
	cout << "expect: 3" << endl;
	cout << "result: " << res1 << endl;

	cout << "test 2" << endl;
	vector<int> test2{2};
	int res2 = coinChange(test2, 3);
	printVector(test2); cout << ", 3" << endl;
	cout << "expect: -1" << endl;
	cout << "result: " << res2 << endl;

	cout << "test 3" << endl;
	vector<int> test3{1, 3};
	int res3 = coinChange(test3, 2);
	printVector(test3); cout << ", 2" << endl;
	cout << "expect: 2" << endl;
	cout << "result: " << res3 << endl;

	cout << "test4" << endl;
	vector<int> test4{186,419,83,408};
	int res4 = coinChange(test4, 6249);
	printVector(test4); cout << ", 6249" << endl;
	cout << "expect: 20" << endl;
	cout << "result: " << res4 << endl;

	cout << "test5" << endl;
	vector<int> test5{1};
	int res5 = coinChange(test5, 2);
	printVector(test5); cout << ", 2" << endl;
	cout << "expect: 2" << endl;
	cout << "result: " << res5 << endl;

	return 0;
}