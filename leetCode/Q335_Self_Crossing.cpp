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
#include <utility>
#include <vector>

struct point
{
	int x, y;
	point(int x_i, int y_i):x(x_i), y(y_i){}
	point():x(0), y(0){}
};

// boundary line
// b save the boundary value, y for horiz, x for veritcal
// range save the line span,  x span for hor, y span for vertical
struct bLine
{
	pair<int, int> range;
	int b;
	hline(int x1, int x2, int y_i):b(y_i){ 
		if (x1 < x2) {
			range = pair<int, int>{x1, x2};
		} else {
			range = pair<int, int>{x2, x1};
		}
	}
	hline():range(pair<int,int>(0,0)), b(0){}
	bool isCrossHLine(const point& start, const point& end) {
		assert(start.x == end.x);
		if(start.x < range.first || start.x > range.second) {
			return false;
		}
		if( (start.y <= b && b <= end.y) || (end.y <= b && b <= start.y) ) {
			return true;
		}
		return false;
	}
	bool isCrossVLine(const point& start, const point& end) {
		assert(start.y == end.y);
		if(start.y < range.first || start.y > range.second) {
			return false;
		}
		if( (start.x <= b && b <= end.x) || (end.x <= b && b <= start.x)) {
			return true;
		}
		return false;
	}
};
bool isSelfCrossing(vector<int>& x) {
	bool res;
	int sz = (int)x.size();
	if(sz <= 3) {
		return false;
	}

	// vertial Left, vertical Right, hor top, hor bottom
	bLine arr[4];
	bLine holder;
	point prev;
	point curr;
	for (int i = 0; i < 3; i++) {
		
	}


}

int Q335_Self_Crossing()
{
	printf("inside of Q335_Self_Crossing\n");
	return 0;
}