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

string convertNumToStr(int num)
{
	stack<int> digits;
	string res = "";
	int base = 10;
	while(num) {
		digits.push(num % base);
		num /= base;
	}
	while(!digits.empty()) {
		res += to_string(digits.top());
		digits.pop();
	}
	return res;
}

string largestNumber(vector<int>& nums) {
	string res;
	vector<string> strs;
	size_t sz = nums.size();
	if (sz == 1) {
		// return nums[0];
	}
	
	for(size_t i = 0; i < sz; i++) {
		strs.push_back(convertNumToStr(nums[i]));
	}

	for(vector<string>::iterator it=strs.begin(); it != strs.end(); it++) {
		
	}

	return res;
}

int Q179_LargestNumber()
{
	int num = 32995;
	string str = convertNumToStr(num);
	for(size_t sz = 0; sz < str.size(); sz++) {
		printf("%c", str[sz]);
	}
	return 0;
}