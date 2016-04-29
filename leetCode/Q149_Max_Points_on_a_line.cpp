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
// Test case:
// [[560,248],[0,16],[30,250],[950,187],[630,277],[950,187],[-212,-268],[-287,-222],[53,37],[-280,-100],[-1,-14],[-5,4],[-35,-387],[-95,11],[-70,-13],[-700,-274],[-95,11],[-2,-33],[3,62],[-4,-47],[106,98],[-7,-65],[-8,-71],[-8,-147],[5,5],[-5,-90],[-420,-158],[-420,-158],[-350,-129],[-475,-53],[-4,-47],[-380,-37],[0,-24],[35,299],[-8,-71],[-2,-6],[8,25],[6,13],[-106,-146],[53,37],[-7,-128],[-5,-1],[-318,-390],[-15,-191],[-665,-85],[318,342],[7,138],[-570,-69],[-9,-4],[0,-9],[1,-7],[-51,23],[4,1],[-7,5],[-280,-100],[700,306],[0,-23],[-7,-4],[-246,-184],[350,161],[-424,-512],[35,299],[0,-24],[-140,-42],[-760,-101],[-9,-9],[140,74],[-285,-21],[-350,-129],[-6,9],[-630,-245],[700,306],[1,-17],[0,16],[-70,-13],[1,24],[-328,-260],[-34,26],[7,-5],[-371,-451],[-570,-69],[0,27],[-7,-65],[-9,-166],[-475,-53],[-68,20],[210,103],[700,306],[7,-6],[-3,-52],[-106,-146],[560,248],[10,6],[6,119],[0,2],[-41,6],[7,19],[30,250]]
// Author: Binlong Li
// Date: 04/19/2016
#include "..\inc\utils.h"
#include <map>
#include <vector>
#include <algorithm>


using namespace std;

struct line{
	double k;
	int b;
	int count;
	line():k(0), b(0) {}
	line(double ki, int bi):k(ki), b(bi), count(1){}
	bool operator == (const line &rhs) const { return this->k == rhs.k && this->b == rhs.b;}

};

// line management class
class line_man{
public:
	void checkline(const line &il, int& max);
private: 
	vector<line> lines;
};

void line_man::checkline(const line & il, int& max)
{
	// Go over all the lines in the vector
	vector<line>::iterator it = lines.begin();
	for(;it != lines.end(); it++) {
		if(*it == il) {
			(*it).count++;
			max = (*it).count > max ? (*it).count : max;
			break;
		}
	}

	lines.push_back(il);
}

int maxPoints(vector<Point>& points)
{
	map<line, int> lines; // non-vertical line
	map<int, int> ver; // vertical line

	line_man lm;
	int sz = points.size();
	if(sz == 0 || sz == 1){
		return 0;
	}

	// The first point will be saved in ver
	int max = 0;
	for(int i = 0; i < sz; i++){
		Point p1 = points[i];
		map<int, int>::iterator v_iter = ver.find(p1.x);
		if(v_iter != ver.end()){
			v_iter->second++;
			if(v_iter->second > max) {
				max = v_iter->second;
			}
		} else {
			ver[p1.x] = 1;
			if(1 > max) {
				max = 1;
			}
		}



		for(int j = 0; j < i; j++){
			Point p2 = points[j];
			if(p2.x != p1.x) {
				line tmpLine(double(p2.y - p1.y) / double(p2.x - p1.x), p1.y - p2.y);
				lm.checkline(tmpLine, max);
			}
		}
	}
	return max;
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

	int max1 = maxPoints(tc1);
	printf("test case 1 result: %d\n", max1);

	return 0;
}