
// Given a list of non negative integers, arrange them such that they form the largest number.
// 
// For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.
// 
// Note: The result may be very large, so you need to return a string instead of an integer.
// 
// string largestNumber(vector<int>& nums) {
//        
//     }
// Author: Binlong Li
// Date: 05/06/2016


#include "..\inc\utils.h"
#include <string> 
#include <vector>
#include <stack>

using namespace std;

class num
{
public:
	num(int n)
	{
		num_keeper = n;
		stack<int> s;
        if (n == 0) {
            ndigs = 1;
            digs.push_back(0);
        } else {
            while (n) {
                s.push(n % 10);
                n /= 10;
            }
            while (!s.empty()) {
                digs.push_back(s.top());
                s.pop();
            }
            ndigs = (int)(digs.size());
        }		
	}

	bool operator >= (const num &other) const {
		double self = num_keeper * pow(10, other.ndigs) + other.num_keeper;
		double op = other.num_keeper * pow(10, ndigs) + num_keeper;

		if (self >= op) {
			return true;
		} else {
			return false;
		}
		// int iterNum = ndigs > other.ndigs ? ndigs : other.ndigs;
		// for(int i = 0; i < iterNum; i++) {
		// 	int selfDig = digs[i % ndigs];
		// 	int otherDig = other.digs[i % other.ndigs];
		// 	if(selfDig > otherDig ) {
		// 		return true;
		// 	}
		// 	if(selfDig < otherDig) {
		// 		return false;
		// 	}
		// }
		// // equal case
		// return true;
	}

	int num_keeper;
	vector<int> digs;
	int ndigs;
};

void merge(vector<num>& data, int low, int middle, int high) 
{
	vector<num> help(data);

	int left = low;
	int right = middle + 1;
	int current = low;

	while(left <= middle && right <= high) {
		if(help[left] >= help[right]) {
			data[current++] = help[left++];
		} else {
			data[current++] = help[right++];
		}
	}

	int residule = middle - left;
	for(int i = 0; i <= residule; i++) {
		data[current++] = help[left++];
	}
}

void mergesort(vector<num>& data, int low, int high) 
{
	if(low < high) {
		int middle = (low + high) / 2;
		mergesort(data, low, middle);
		mergesort(data, middle + 1, high);
		merge(data, low, middle, high);
	}
}

string largestNumber(vector<int>& nums) {
	string res = "";
	vector<num> self_nums;
	size_t sz = nums.size();
	int sum = 0;
	for(size_t i = 0; i < sz; i++) {
		sum += nums[i];
		num self_num(nums[i]);
		self_nums.push_back(self_num);
	}

	if (sum == 0) {
		return to_string(0);
	}

	mergesort(self_nums, 0, sz - 1);

	for(size_t i = 0; i < sz; i++) {
		res += to_string(self_nums[i].num_keeper);
	}


	return res;
}

int Q179_LargestNumber()
{
	vector<int> dataTest1{3, 30, 34, 5, 9};
	cout << "dataTest1 expect result: 9534330, result: " << largestNumber(dataTest1) << endl;

	vector<int> dataTest2{1,2,3,4,5,6,7,8,9,0};
	cout << "dataTest2 expect result: 9876543210, result: " << largestNumber(dataTest2) << endl;

	vector<int> dataTest3{121,12};
	cout << "dataTest3 expect result: 12121, result: " << largestNumber(dataTest3) << endl;

	vector<int> dataTest4{0, 0};
	cout << "dataTest4 expect result: 0, result: " << largestNumber(dataTest4) << endl;

	return 0;
}