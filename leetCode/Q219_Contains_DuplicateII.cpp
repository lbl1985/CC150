// Given an array of integers and an integer k, find out whether there are two distinct indices i and j in the array such that nums[i] = nums[j] and the difference between i and j is at most k. 
// bool containsNearbyDuplicate(vector<int>& nums, int k)
// Author: Binlong Li
// Date: 05/29/2016

#include "..\inc\utils.h"
#include <unordered_map>
using namespace std;

bool containsNearbyDuplicate(vector<int>&nums, int k)
{
	int sz = (int)nums.size();
    if(sz < 2) return false;
    unordered_map<int, vector<int>> dict;
    for (int i = 0; i < sz; i++){
        int tmp = nums[i];
        if(dict.count(tmp)) {
            vector<int>& v = dict[nums[i]];
            int l = v.size();
            for(int j = 0; j < l; j++){
                if(i - v[j] <= k){
                    return true;
                }
            }
            v.push_back(i);
        } else {
            vector<int> tmpV;
            tmpV.push_back(i);
            dict[tmp] = tmpV;
        }
    }
    return false;
}

int Q219_Contains_DuplicateII()
{
	printf("inside of Q219_Contains_DuplicateII\n");
	vector<int> test1{1, 2, 3, 1, 2, 3}; int t1 = 2;
	printf("test1 expect: false: result: %d\n", containsNearbyDuplicate(test1, t1));

	return 0;
}