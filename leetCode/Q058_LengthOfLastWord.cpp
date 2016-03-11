// Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.
// 
// If the last word does not exist, return 0.
// 
// Note: A word is defined as a character sequence consists of non-space characters only.
// 
// For example, 
//  Given s = "Hello World",
//  return 5. 
// class Solution {
// public:
//     int lengthOfLastWord(string s) {
//         
//     }
// };
// Author: Binlong Li
// Date:   03/10/2016
// Finish: 03/10/2016

#include "..\inc\utils.h"
#include <string>

using namespace std;

int lengthOfLastWord(string s) {
	size_t sz = s.size();
	int lolw = 0;
	int init = true;
	char preCha = s[0];
	char curCha;
	for(size_t i = 0; i < sz; i++ ){
		curCha = s[i];
		if(curCha != ' '){
			if(preCha == ' '){
				lolw = 1;				
			} else {
				lolw++;
			}
		} 
		preCha = curCha;
	}
	return lolw;
}

int Q058_LengthOfLastWord(){
	printf("inside of Q058_LengthOfLastWord()\n");
	cout << "a:" << lengthOfLastWord("a") << endl; // expected 1
	cout << "a :" << lengthOfLastWord("a ") << endl; // expected 1
	cout <<  "b   a    :" << lengthOfLastWord( "b   a    ") << endl; // expected 1

	return 0;
}