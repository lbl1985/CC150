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
// [[29,87],[145,227],[400,84],[800,179],[60,950],[560,122],[-6,5],[-87,-53],[-64,-118],[-204,-388],[720,160],[-232,-228],[-72,-135],[-102,-163],[-68,-88],[-116,-95],[-34,-13],[170,437],[40,103],[0,-38],[-10,-7],[-36,-114],[238,587],[-340,-140],[-7,2],[36,586],[60,950],[-42,-597],[-4,-6],[0,18],[36,586],[18,0],[-720,-182],[240,46],[5,-6],[261,367],[-203,-193],[240,46],[400,84],[72,114],[0,62],[-42,-597],[-170,-76],[-174,-158],[68,212],[-480,-125],[5,-6],[0,-38],[174,262],[34,137],[-232,-187],[-232,-228],[232,332],[-64,-118],[-240,-68],[272,662],[-40,-67],[203,158],[-203,-164],[272,662],[56,137],[4,-1],[-18,-233],[240,46],[-3,2],[640,141],[-480,-125],[-29,17],[-64,-118],[800,179],[-56,-101],[36,586],[-64,-118],[-87,-53],[-29,17],[320,65],[7,5],[40,103],[136,362],[-320,-87],[-5,5],[-340,-688],[-232,-228],[9,1],[-27,-95],[7,-5],[58,122],[48,120],[8,35],[-272,-538],[34,137],[-800,-201],[-68,-88],[29,87],[160,27],[72,171],[261,367],[-56,-101],[-9,-2],[0,52],[-6,-7],[170,437],[-261,-210],[-48,-84],[-63,-171],[-24,-33],[-68,-88],[-204,-388],[40,103],[34,137],[-204,-388],[-400,-106]]
// Author: Binlong Li
// Date: 04/19/2016
// Finish: 05/03/2016
#include "..\inc\utils.h"
#include <map>
#include <vector>
#include <algorithm>


using namespace std;

int maxPoints(vector<Point>& points)
{
	int sz = points.size();

	if(sz == 0){
		return 0;
	} else if(sz == 1) {
		return 1;
	}

	// The first point will be saved in ver
	int max = 0;
	map<double, int> lines; // first->slope, second->count
	map<double, int>::iterator it;
	int verPoints = 1;		
	int identicalPoint = 0;
	for(int i = 0; i < sz; i++){
		for(int j = 0; j < sz; j++) {
			if(i != j) {
				if(points[i].x == points[j].x) {
					verPoints++;
					max = verPoints > max ? verPoints : max;
				} else {
					double slope = (double)(points[j].y - points[i].y) / (double)(points[j].x - points[i].x);
					it = lines.find(slope);
					if(it != lines.end()) {
						it->second++;
						max = it->second > max ? it->second : max;
					} else {
						lines.insert(pair<double, int>(slope, 2));
						max = max ? max : 2;
					}
				}

                if (points[i].x == points[j].x && points[i].y == points[j].y) {
                    identicalPoint++;
                }
			}
		}

		if(identicalPoint) {
			for(it = lines.begin(); it != lines.end(); it++) {
				it->second += identicalPoint;
				max = it->second > max ? it->second : max;
			}			
		}
		lines.clear();
		identicalPoint = 0;
		verPoints = 1;
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

vector<Point> createTestCase2()
{
	std::vector<Point> v;
	v.push_back(Point(1, 1));
	v.push_back(Point(1, 1));
	v.push_back(Point(2, 2));
	v.push_back(Point(2, 2));
	return v;
}

vector<Point> createTestCase3()
{
	std::vector<Point> v;
	v.push_back(Point(84, 250));
	v.push_back(Point(0,0));
	v.push_back(Point(1,0));
	v.push_back(Point(0,-70));
	v.push_back(Point(0,-70));
	v.push_back(Point(1,-1));
	v.push_back(Point(21,10));
	v.push_back(Point(42,90));
	v.push_back(Point(-42,-230));
	return v;
}

int Q149_Max_Points_on_aline()
{
	printf("inside Q149_Max_Points_on_aline\n");
	// Test case 1
	vector<Point> tc1 = createTestCase1();
	printf("result of test case 1, expect 5, result is: %d\n", maxPoints(tc1));

	std::vector<Point> tc2 = createTestCase2();
	printf("result of test case 2, expect 4, result is: %d\n", maxPoints(tc2));

	std::vector<Point> tc3 = createTestCase3();
	printf("result of test case 3, expect 6, result is: %d\n", maxPoints(tc3));
	return 0;
}