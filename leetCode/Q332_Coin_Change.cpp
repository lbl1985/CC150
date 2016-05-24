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

#include "..\inc\utils.h"
#include <vector>
#include <algorithm>
using namespace std;

int coinChange(vector<int>& coins, int amount) {
	int res = 0;
	sort(coins.begin(), coins.end());
	
	return res;
}


int Q332_Coin_Change()
{
	printf("inside of Q332_Coin_Change\n");
	vector<int> test1{5, 1, 2};
	coinChange(test1, 11);
	return 0;
}