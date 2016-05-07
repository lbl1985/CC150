// Given a non-empty array of integers, return the k most frequent elements.

// For example,
//  Given [1,1,1,2,2,3] and k = 2, return [1,2]. 

// Note: 

// •You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
// •Your algorithm's time complexity must be better than O(n log n), where n is the array's size.

// vector<int> topKFrequent(vector<int>& nums, int k) {
        
//     }
// Author: Binlong Li
// Date: 05/04/2016
// Finish: 05/04/2016

#include "..\inc\utils.h"
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k)
{
	size_t sz = nums.size();	
	map<int, int> dict;
	map<int, int>::iterator it;
	
	for(size_t i = 0; i < sz; i++) {
		it = dict.find(nums[i]);
		// unique value
		if(it == dict.end()) {
			dict.insert(pair<int, int>(nums[i], 1));			
		} else {
			// duplicate value
			it->second++;
		}
	}
	vector<pair<int, int> >  pairs;
	for(auto iter = dict.begin(); iter != dict.end(); iter++) {
		pairs.push_back(*iter);
	}

	sort(pairs.begin(), pairs.end(), [=](pair<int, int>&a, pair<int, int>&b)
	{
		return a.second > b.second;
	});

	vector<int> res;
	auto iter = pairs.begin();
	for(int i = 0; i < k; i++) {
		res.push_back(iter->first);
		iter++;
	}
	return res;
}

int Q347_TopKFrequentElements()
{
	vector<int> v1{1,1,1,2,2,3};
	printf("test case 1: 1,1,1,2,2,3, k = 2 expect[1,2], res:");
	printVector<int>(topKFrequent(v1, 2));

	return 0;
}