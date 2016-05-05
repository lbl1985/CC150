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
// 

#include "..\inc\utils.h"
#include <vector>
#include <map>
using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k)
{
	size_t sz = nums.size();	
	map<int, int> dict;
	map<int, int>::iterator it;
	
	int* freqValue = new int[k];
	int* freqCount = new int[k];
	memset(freqValue, 0, k * sizeof(int));
	memset(freqCount, 0, k * sizeof(int));

	int minCount = k > 1 ? 0 : 1;
	int minCountId = k > 1 ? 1 : 0;
	freqValue[0] = nums[0];
	freqCount[0] = 1;

	for(int i = 1; i < sz; i++) {
		it = dict.find(nums[i]);
		// unique value
		if(it == dict.end()) {
			dict.insert(pair<int, int>(nums[i], 1));
			if(!minCount) {
				freqValue[minCountId] = nums[i];
				freqCount[minCountId] = 1;
				if (minCountId < k - 1) {
					minCountId++;
				} else {
					minCount = 1;
				}
			}
		} else {
			// duplicate value
			it->second++;
			if(it->second > minCount) {
				
			}
		}
	}
	delete [] buffer;
}

int Q347_TopKFrequentElements()
{
	printf("inside of Q347_TopKFrequentElements\n");
	return 0;
}