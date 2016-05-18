// 344 Reverse String
// Write a function that takes a string as input and returns the string reversed.

// Example:
//  Given s = "hello", return "olleh".

//  string reverseString(string s) {
        
//     }
// Author: Binlong Li
// Date: 05/18/2016
// Finish: 05/18/2016
#include "..\inc\utils.h"
#include <string> 
using namespace std;

string reverseString(string s)
{
	string res ("");
	size_t sz = s.size();
	if(sz == 0) {
		return res;
	} else if (sz == 1) {
		return s;
	} else {
		for(int i = (int)sz-1; i >= 0; i--) {
			res += s[i];
		}
	}
	return res;
}

int Q344_ReverseString()
{
	printf("inside of Q344_ReverseString\n");
	string test1("hello");
	cout << "result of " << test1 << " is " << reverseString(test1) << endl;
	return 0;
}