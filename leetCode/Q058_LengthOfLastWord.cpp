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

#include "..\inc\utils.h"
#include <string>

using namespace std;
const int max_int = 65536;

int lengthOfLastWord(string s) {
	size_t sz = s.size();
	if(sz == 0){
		return 0;
	}
	int prevSpace = -1;
	int lastSpace = max_int;
	for(size_t i = 0; i < sz; i++){
		if(s[i] == ' '){
			if(lastSpace != max_int){
				prevSpace = lastSpace;	
			}			
			lastSpace = (int)i;
		}
	}
	if(lastSpace != max_int){
		if(lastSpace == sz - 1){
			return (lastSpace - 1) - prevSpace;
		} else {
			return sz - 1 - lastSpace;	
		}		
	} else {
		return sz;
	}
}

int Q058_LengthOfLastWord(){
	printf("inside of Q058_LengthOfLastWord()\n");
	cout << "a:" << lengthOfLastWord("a") << endl;
	cout << "a :" << lengthOfLastWord("a ") << endl;

	return 0;
}