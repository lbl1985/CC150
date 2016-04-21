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

struct line{
	double k;
	double b;
	line():k(0), b(0) {}
	line(double ki, double bi):k(ki), b(bi){}
};

int maxPoints(vector<Point>& points)
{
	map<line, vector<Point>> lines; // non-vertical line
	map<int, vector<Point>> ver; // vertical line

	int sz = points.size();
	if(sz == 0 || sz == 1){
		return 0;
	}

	for(int i = 1; i < sz; i++){
		Point p1 = points[i];
		for(int j = 0; j < i; j++){
			Point p2 = points[j];
			if(p1.x == p2.x){
				if(ver.count(p1.x) > 0){

				}
			}
		}
	}
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

	map<int, vector<int>> testMap;
	vector<int> tmpv;
	tmpv.push_back(1);
	tmpv.push_back(2);
	testMap[1] = tmpv;
	printVector<int>(testMap[1]);

	map<int, vector<int>>::iterator mapIter = testMap.find(1);
	mapIter->second.push_back(3);

	// vector<int> tmpv3 = testMap[1];
	printVector<int>(testMap[1]);

	return 0;
}