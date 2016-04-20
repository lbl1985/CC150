// Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.
/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
// class Solution {
// public:
//     int maxPoints(vector<Point>& points) {
        
//     }
// };
// Author: Binlong Li
// Date: 04/19/2016
#include "..\inc\utils.h"
#include <map>
#include <vector>

using namespace std;
int maxPoints(vector<Point>& points)
{
	return 0;
}

vector<Point> createTestCase1()
{
	vector<Point> tmpv;
	tmpv.push_back(Point(1, 2));
	tmpv.push_back(Point(2, 4));
	tmpv.push_back(Point(3, 6));
	tmpv.push_back(Point(2, 2));
	tmpv.push_back(Point(3, 2));
	tmpv.push_back(Point(3, 4));
	tmpv.push_back(Point(3, 5));
	tmpv.push_back(Point(3, 7));
	return tmpv;
}

int Q149_Max_Points_on_aline()
{
	printf("inside Q149_Max_Points_on_aline\n");
	// Test case 1
	vector<Point> tc1 = createTestCase1();
	printf("result of test case 1 is: %d\n", maxPoints(tc1));
	return 0;
}