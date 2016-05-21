// You are given an array x of n positive numbers. You start at point (0,0) and moves x[0] metres to the north, then x[1] metres to the west, x[2] metres to the south, x[3] metres to the east and so on. In other words, after each move your direction changes counter-clockwise. 

// Write a one-pass algorithm with O(1) extra space to determine, if your path crosses itself, or not. 

// Example 1:

// Given x = [2, 1, 1, 2],
// ┌───┐
// │   │
// └───┼──>
//     │

// Return true (self crossing)



// Example 2:

// Given x = [1, 2, 3, 4],
// ┌──────┐
// │      │
// │
// │
// └────────────>

// Return false (not self crossing)



// Example 3:

// Given x = [1, 1, 1, 1],
// ┌───┐
// │   │
// └───┼>

// Return true (self crossing)

// bool isSelfCrossing(vector<int>& x) {
        
//     }

// Author: Binlong Li  

#include "..\inc\utils.h"
#include <vector>


bool isSelfCrossing(vector<int>& x) {
	int sz = (int)x.size();
	if(sz <= 3) {
		return false;
	}
	int i = 2; 
	// keep expanding
	for(i = 2; i < sz && x[i] > x[i - 2]; i++);
	// In transition stage from expanding to shrinking
	// Consider whether transition steip step over previous queued up distance
	// if so, we need to modify the data for collition detection
	if(i < sz && i > 2 && x[i] >= x[i - 2] - ((i >= 4) ? x[i-4] : 0)) {
		x[i - 1] -= x[i - 3];
	}
	// keep shrinking
	for(i++; i < sz && x[i] < x[i-2] ; i++);

	return i < sz;


}

int Q335_Self_Crossing()
{
	printf("inside of Q335_Self_Crossing\n");
	vector<int> test1{2, 1, 1, 2};
	printf("test 1 [2, 1, 1, 2] expect: true, result: %s\n", isSelfCrossing(test1) ? "true" : "false");
	vector<int> test2{1, 2, 3, 4};
	printf("test 2 [1, 2, 3, 4] expect: false, result: %s\n", isSelfCrossing(test2) ? "true" : "false");
	vector<int> test3{1, 1, 1, 1};
	printf("test 3 [1, 1, 1, 1] expect: true, result: %s\n", isSelfCrossing(test3) ? "true" : "false");
	vector<int> test4{1, 1, 2, 2, 1, 1};
	printf("test 4 [1, 1, 2, 2, 1, 1] expect: true, result: %s\n", isSelfCrossing(test4) ? "true" : "false");
	vector<int> test5{3,3,3,2,1,1};
	printf("test 5 [3,3,3,2,1,1] expect false, result: %s\n", isSelfCrossing(test5) ? "true" : "false");
	vector<int> test6{1,1,2,1,1};
	printf("test 6  [1,1,2,1,1] expect true, result: %s\n", isSelfCrossing(test6) ? "true" : "false");
	return 0;
}