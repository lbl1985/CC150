// Write a function that takes a string as input and reverse only the vowels of a string.
// 
// Example 1:
//  Given s = "hello", return "holle". 
// 
// Example 2:
//  Given s = "leetcode", return "leotcede". 
// 
// string reverseVowels(string s) {
//         
//     }
// 
// Author: Binlong Li
// Date: 05/04/2016
// Finish: 05/04/2016

#include "..\inc\utils.h"
#include <string>
using namespace std;

bool isVowel(char c) 
{
	if('a' == c || 'e' == c || 'i' == c || 'o' == c || 'u' == c ||
	   'A' == c || 'E' == c || 'I' == c || 'O' == c || 'U' == c) {
		return true;
	} else {
		return false;
	}
}
string reverseVowels(string s) {
	size_t sz = s.size();
	if(sz <= 1) {
		return s;
	}

	int a = 0;
	int b = sz - 1;
	while(a < b) {
		if(isVowel(s[a]) && isVowel(s[b])) {
			char c = s[a];
			s[a] = s[b];
			s[b] = c;
			a++;
			b--;
		}
		if(!isVowel(s[a])) {
			a++;
		}
		if(!isVowel(s[b])) {
			b--;
		}
	}
	return s;
}

int Q345_Reverse_vowels_of_a_string()
{
	string s1("hello");
	cout << s1 << ": " << reverseVowels(s1) << endl;
	string s2("leetcode");
	cout << s2 << ": " << reverseVowels(s2) << endl;

	return 0;
}