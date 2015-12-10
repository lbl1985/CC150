// 1.8 Assume you hava a method isSubstring which checks if one word is a substring of another. 
// given two strings, s1 and s2, write code to check if s2 is a rotation of s2 using only one
// call to isSubstring (e.g., "waterbottle" is a rotatioin of "erbottlewat").

#include <iostream>
#include <vector>
#include <string>
#include "..\utils.h"

using namespace std;


bool isSubString(string* s1, string* s2)
{
    if (s1 == nullptr || s2 == nullptr) {
        return 0;
    }

    if ((*s1).length() != (*s2).length()) {
        return 0;
    }

    int count[256] = { 0 };
    int len = (*s1).length();
    for (int i = 0; i < len; i++) {
        count[(*s1)[i]]++;
    }

    for (int i = 0; i < len; i++) {
        if (!(count[(*s2)[i]]--)) {
            return false;
        }
    }
    return 1;
}

int main()
{
    vector<string> s1 = { "hello world", "test", "Seattle" };
    vector<string> s2 = { "world hello", "lalal", "Coll" };

    if (s1.size() != s2.size()) {
        printf("string vector size is different!!\n");
        return 1;
    }

    for (uint i = 0; i < s1.size(); i++) {
        bool bIsSubString = isSubString(&s1[i], &s2[i]);
        cout << "String " << s1[i] << " and " << s2[i] << " is " << (bIsSubString ? "" : " not ") << "substring" << endl;        
    }

    return 0;

}