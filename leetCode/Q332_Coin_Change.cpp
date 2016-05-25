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
	int res = -1;
	int sz = (int)coins.size();
	sort(coins.begin(), coins.end());
	if(amount == 0) {
		return 0;
	}
	// amount is less than the smallest of the coins, return -1
	if(amount < coins[0]) {
		return -1;
	}
	for(int i = 0; i < sz; i++) {
		if(amount == coins[i]) {
			return 1;
		}
	}
	for(int i = sz - 1; i >= 0; i--) {		
		if (amount < coins[i]) {
			continue;
		}
		int n = amount / coins[i];
		int tRes = coinChange(coins, amount - n * coins[i]);
		if (tRes == -1 && sz > 1) {
			n = n - 1;
			tRes = coinChange(coins, amount - n * coins[i]);
			if(tRes != -1) {
				return tRes + n;
			}
		} else if(sz > 1) {
			return tRes + n;
		}
	}
	
	return res;
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
	int res4 = coinChange(test4, 2);
	printVector(test4); cout << ", 6249" << endl;
	cout << "expect: None" << endl;
	cout << "result: " << res4 << endl;


	return 0;
}