// Given a non negative integer number num. For every numbers i in the range 0 ≤ i ≤ num calculate the number of 1's in their binary representation and return them as an array. 

// Example:
//  For num = 5 you should return [0,1,1,2,1,2]. 

// Follow up: 
// •It is very easy to come up with a solution with run time O(n*sizeof(integer)). But can you do it in linear time O(n) /possibly in a single pass?
// •Space complexity should be O(n).
// •Can you do it like a boss? Do it without using any builtin function like __builtin_popcount in c++ or in any other language.

// vector<int> countBits(int num) {
        
//     }
// Author: Binlong Li
// Date: 05/19/2016
// Finish: 05/19/2016

#include "..\inc\utils.h"
#include <vector>
using namespace std;

vector<int> countBits(int num) {
	vector<int> res;
	int start = 0; // start point for repeating
	int end = 0;   // end point for repeating
	int dis = 0;   // distance between end and start
	bool additonal = false;  // if this the second round, if yes, add 1
	
	for(int i = 0; i <= num; i++) {
		switch (i) {
			case 0:
				res.push_back(0);
				continue;
			case 1:
			  	res.push_back(1);
			  	continue;
		  	case 2:
		  		res.push_back(1);
		  		start = 2;
		  		continue;
	  		case 3:
	  			res.push_back(2);
	  			continue;
  			case 4:
  				res.push_back(1);
  				end = 4;
  				dis = end - start;
  				continue;
		}
		if (i == end * 2) {
			start = end;
			end = i;
			dis = end - start;
			additonal = false;
			res.push_back(1);
			continue;
		}
		if((i - end) == dis){
			res.push_back(2);
			additonal = true;
			continue;
		}
		int tmp = res[start + (i - end)] + (additonal ? 1 : 0);
		res.push_back(tmp);
	}
	return res;
}

int Q338_CountingBits(){
	printf("inside of Q338_CountingBits\n");
	vector<int> testcase1 = countBits(32);
	printVector(testcase1);
	return 0;
}