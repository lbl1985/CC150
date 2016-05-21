// Given a list of unique words. Find all pairs of distinct indices (i, j) in the given list, so that the concatenation of the two words, i.e. words[i] + words[j] is a palindrome. 

// Example 1:
//  Given words = ["bat", "tab", "cat"]
//  Return [[0, 1], [1, 0]]
//  The palindromes are ["battab", "tabbat"]

// Example 2:
//  Given words = ["abcd", "dcba", "lls", "s", "sssll"]
//  Return [[0, 1], [1, 0], [3, 2], [2, 4]]
//  The palindromes are ["dcbaabcd", "abcddcba", "slls", "llssssll"]

// vector<vector<int>> palindromePairs(vector<string>& words) {
        
//     }
// Author: Binlong Li
// Date: 05/21/2016

#include "..\inc\utils.h"
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool isPalindrome(string str) {
	string copy(str);
	reverse(copy.begin(), copy.end());
	return (str == copy) ? true : false;
}

vector<vector<int>> palindromePairs(vector<string>& words) {
    vector<vector<int>> res;
    int sz = (int)words.size();
    for(int i = 0; i < sz; i++) {
    	for(int j = i+1; j < sz; j++) {
    		if( (*words[i].begin()) == *(words[j].end()-1) && isPalindrome( words[i] + words[j] )) {
    			vector<int> tmp; tmp.push_back(i); tmp.push_back(j);
    			res.push_back(tmp);
    		}
    		if( (*words[j].begin()) == *(words[i].end()-1) && isPalindrome( words[j] + words[i])) {
    			vector<int> tmp; tmp.push_back(j); tmp.push_back(i);
    			res.push_back(tmp);
    		}
    	}
    }
    return res;
}



void printRes(vector< vector<int> > in) {
	for(size_t i = 0; i < in.size(); i++ ) {
		printVector<int>(in[i]);
	}
}

int Q336_Palindrome_pairs()
{
	printf("inside of Q336_Palindrome_pairs\n");
	vector<string> words1; 
	words1.push_back("bat"); words1.push_back("tab"); words1.push_back("cat");
	vector<vector<int>> res1 = palindromePairs(words1);
	cout << "test 1 result: expect [[0,1], [1, 0]] " << endl;
	printRes(res1);
	vector<string> words2;
	words2.push_back("abcd"); words2.push_back("dcba"); words2.push_back("lls"); words2.push_back("s"); words2.push_back("sssll");
	vector<vector<int>> res2 = palindromePairs(words2);
	cout << "test 2 result: expect [[0, 1], [1, 0], [3, 2], [2, 4]] " << endl;
	printRes(res2);
	return 0;
}