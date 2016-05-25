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

vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
	vector<int> res;
	int range;
	struct groupStatus{
		int endIdx;
		int sz;
		int cur;
		int l; // largest number
		int li; // largest number index
		groupStatus():endIdx(0), sz(0), cur(0), l(-1), li(-1){}
		
	};
	int endIdx[2] = {0, 0};
	int sz{2} = {0, 0};
	int cur[2] = {0, 0};
	int l{2} = {-1, -1};
	int li{2} = {-1, -1};

	for(int i = 0; i < k; i++) {
		range = k - i;
		endIdx[0] = (cur[0] + range) < sz[0] ? (cur[0] + range) : sz[0];
		endIdx2 = (cur2 + range) < sz2 ? (cur2 + range) : sz2;
		for(int j = cur1; j < endIdx1; j++) {
			if(nums1[j] > l) {
				l = nums1[j];
				lg = 1; li = j;
			}
		}
		for(int j = cur2; j< endIdx2; j++) {
			if(nums2[j] > l) {
				l = nums2[j];
				lg = 2; li = j;
			}
		}


	}

}

int Q321_Create_Maximum_Number()
{
	printf("inside of Q321_Create_Maximum_Number\n");
	return 0;
}