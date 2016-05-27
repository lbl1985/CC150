// Given two arrays of length m and n with digits 0-9 representing two numbers. Create the maximum number of length k <= m + n from digits of the two. The relative order of the digits from the same array must be preserved. Return an array of the k digits. You should try to optimize your time and space complexity. 
// Example 1:
// nums1 = [3, 4, 6, 5]
//  nums2 = [9, 1, 2, 5, 8, 3]
//  k = 5
//  return [9, 8, 6, 5, 3] 
// Example 2:
// nums1 = [6, 7]
//  nums2 = [6, 0, 4]
//  k = 5
//  return [6, 7, 6, 0, 4] 
// Example 3:
// nums1 = [3, 9]
//  nums2 = [8, 9]
//  k = 3
//  return [9, 8, 9] 
// vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
// }
// Author: Binlong Li
// Date: 05/24/2016

#include "..\inc\utils.h"
#include <utility>
#include <vector>

using namespace std;

	struct groupStatus{
		int endIdx;
		int sz;
		int cur;
		int l; // largest number
		int li; // largest number index
		groupStatus():endIdx(0), sz(0), cur(0), l(-1), li(-1){}
		
	};

vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
	vector<int> res;
	int range;
	int endIdx[2] = {0, 0};
	int sz[2] = {(int)nums1.size(), (int)nums2.size()};
	int cur[2] = {0, 0};
	int l[2] = {-1, -1};
	int li[2] = {-1, -1};

	for(int i = 0; i < k; i++) {
		range = k - i;
		endIdx[0] = (cur[0] + range) <= sz[0]? (cur[0] + range) : sz[0];
		endIdx[1] = (cur[1] + range) <= sz[1]? (cur[1] + range) : sz[1];
		for(int j = cur[0]; j < endIdx[0]; j++) {
			if(nums1[j] > l[0]) {
				l[0] = nums1[j];
				li[0] = j;
			}
		}
		for(int j = cur[1]; j< endIdx[1]; j++) {
			if(nums2[j] > l[1]) {
				l[1] = nums2[j];
				li[1] = j;
			}
		}
		if (l[0] >= l[1]) {
			res.push_back(l[0]);
			cur[0] = li[0] + 1 <= sz[0] - 1 ?  li[0] + 1 : sz[0];
			l[0] = -1;
		} else if (l[0] < l[1]) {
			res.push_back(l[1]);
			cur[1] = li[1] + 1 <= sz[1] - 1 ?  li[1] + 1 : sz[1];
			l[1] = -1;
		} 
	}
	return res;

}


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

int Q321_Create_Maximum_Number()
{
	printf("inside of Q321_Create_Maximum_Number\n");
	// nums1 = [3, 4, 6, 5]
//  nums2 = [9, 1, 2, 5, 8, 3]
//  k = 5
//  return [9, 8, 6, 5, 3] 
	cout << "test1" << endl;
	vector<int> t1nums1{3, 4, 6, 5};
	vector<int> t1nums2{9, 1, 2, 5, 8, 3};
	int t1k = 5;
	vector<int> t1res = maxNumber(t1nums1, t1nums2, t1k);
	cout << "expect: [9 8 6 5 3]" << endl;
	cout << "result:"; printVector(t1res);

	// nums1 = [6, 7]
	//  nums2 = [6, 0, 4]
	//  k = 5
	//  return [6, 7, 6, 0, 4] 
	cout << "test2" << endl;
	vector<int> t2nums1{6, 7};
	vector<int> t2nums2{6, 0 , 4};
	int t2k = 5;
	vector<int> t2res = maxNumber(t2nums1, t2nums2, t2k);
	cout << "expect: [6 7 6 0 4]" << endl;
	cout << "result:"; printVector(t2res);

	int test = (int)sqrt(35);
	printf("35 sqrt is: %d\n", test);

	numSquares(1);

	return 0;
}