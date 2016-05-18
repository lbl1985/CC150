// Intersection of Two Arrays
// Given two arrays, write a function to compute their intersection. 

// Example:
//  Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2]. 

// Note:

// •Each element in the result must be unique.
// •The result can be in any order.

// vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        
// }
// Author: Binlong Li
// Date: 05/18/2016
// Finish: 05/18/2016

#include "..\inc\utils.h"
#include <vector>
#include <map>
using namespace std;

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
	vector<int> res;
	size_t sz1 = nums1.size();
	size_t sz2 = nums2.size();
	if (sz1 == 0 || sz2 == 0) {
		return res;
	}

	map<int, bool> inter;
	// init the inter map (dict)
	for(size_t i = 0; i < sz1; i++) {
		int cur = nums1[i];
		auto it = inter.find(cur);
		if (it == inter.end()) {
			inter.insert(pair<int, bool>(cur, false));
		}
	}

	for(size_t i = 0; i < sz2; i++) {
		int cur = nums2[i];
		auto it = inter.find(cur);
		if(it != inter.end()) {
			if(it->second == false) {
				res.push_back(cur);
				it->second = true;
			}
		}
	}

	return res;
}


int Q349_IntersectionOfTwoArrays()
{
	printf ("insdie of Q349_IntersectionOfTwoArrays\n");
	vector<int> test1_nums1{1, 2, 2, 1};
	vector<int> test1_nums2{2, 2};
	printf("result of test 1 is: \n");
	printVector<int>(intersection(test1_nums1, test1_nums2));

	vector<int> test2_nums1{1};
	vector<int> test2_nums2{1};
	printf("result of test 2 is: \n");
	printVector<int>(intersection(test2_nums1, test2_nums2));
	return 0;
}