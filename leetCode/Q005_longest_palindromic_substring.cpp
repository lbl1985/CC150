// Given a string S, find the longest palindromic substring in S. You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.
// 
// string longestPalindrome(string s) {
        
//     }
// Author: Binlong Li
// Date: 05/16/2016
//

#include "..\inc\utils.h"
#include <map>
#include <vector>

using namespace std;

void getCheckBook(map<char, vector<int>>& checkbook, const string& s)
{
	size_t sz = s.size();
	for(size_t i = 0; i < sz; i++) {
		char c = s[i];
		auto it = checkbook.find(c);
		if(it != checkbook.end()) {
			it->second.push_back(i);
		} else {
			vector<int> temp;
			temp.push_back(i);
			checkbook.insert(pair<char, vector<int>>(c, temp));
		}
	}
}

// positive number represent the length of a Palindrome string
// -1 represents not a palindrome string
int isPalindrome(const string& str, int s, int e)
{
	int left = s;
	int right = e;
	while(left < right) {
		if(str[left] == str[right]) {
			left++;
			right--;
		} else {
			return -1;
		}
	}
	return e - s + 1;
}
string longestPalindrome(string s) {
	size_t sz = s.size();
	if (sz == 1) {
		return s;
	}

	map<char, vector<int>> checkbook;
	getCheckBook(checkbook, s);
	int max = 0;
	string res;
	for(auto it = checkbook.begin(); it != checkbook.end(); it++) {
		size_t sz = it->second.size();
		int tmpMax = 0;
		for(size_t i = 0; i < sz; i++) {
			for(size_t j = sz - 1; j > i; j--) {
				int cur = isPalindrome(s, it->second[i], it->second[j]);
				if (cur > max) {
					max = cur;
					res = s.substr(it->second[i], cur);
				}
				if (cur == -1) {
					continue;
				} else if (cur > tmpMax) {
					tmpMax = cur;
				} else {
					break;
				}
			}
		}
	}
	return res;
}


int Q005_longest_palindromic_substring()
{
	printf("inside of Q005_longest_palindromic_substring\n");
	string test1="aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabcaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
	string res1 = longestPalindrome(test1);
	cout << test1.c_str() << endl << res1.c_str() << endl;
	string test2="aaabaaaa";
	string res2 = longestPalindrome(test2);
	cout << test2.c_str() << endl << res2.c_str() << endl;
	string test3 = "aaaabaaa";
	string res3 = longestPalindrome(test3);
	cout << test3.c_str() << endl << res3.c_str() << endl;
	// cout << test1 << endl << longestPalindrome(test1) << endl;
	return 0;
}