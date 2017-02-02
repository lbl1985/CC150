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

void getCheckbook(map<char, vector<int>>& checkbook, const string& s) {
	int sz = s.size();
	for (int i = 0; i < sz; i++) {
		char c = s[i];
		auto it = checkbook.find(c);
		if(it != checkbook.end()) {
			it->second.push_back(i);
		} else {
			vector<int> tmp;
			tmp.push_back(i);
			checkbook.insert(pair<char, vector<int>>(c, tmp));
		}
	}
}

int isPalindrome(const string& str, int s, int e) 
{
	int left = s, right = e;
	while(left <= right) {
		if(str[left] == str[right]) {
			left++;
			right--;
		} else {
			return -1;
		}
	}
	return e - s + 1;
}
// Solution # 1 by using 
string longestPalindrome(string s) {
	int sz = s.size();
	if(sz == 1) {
		return s;
	}
	map<char, vector<int>> checkbook;
	getCheckbook(checkbook, s);
	string res;
	int longest = 0;
	for(int i = 0; i < sz; i++) {
		char c = s[i];
		auto it = checkbook.find(c);
		if(it != checkbook.end()) {
			int j = it->second.size() - 1;
			if(longest > it->second[j] - i + 1) {
				continue;
			}
			for(; j >= 0; j--) {
				int index = it->second[j];
				if(index >= i) {
					int len = isPalindrome(s, i, index);
					if(len > longest) {
						longest = len;
						res = s.substr(i, index - i + 1);
					}
					if(len > 0) {
						break;
					}
				}
			}
		}
		
	}
	return res;
}

// string longestPalindrome(strig s)

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