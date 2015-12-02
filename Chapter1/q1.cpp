// 1.1 Implement an algorithm to determin if a string has all unique 
// characters.What if you cannot use additional data structure ?

#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef unsigned int uint;

bool checkUnique(string s)
{
    
    int u = 0;
    for (unsigned int i = 0; i < s.length(); i++) {
        int c = s[i];
        if (c >= 'a' && c <= 'z') {
            if (u & 1 << (c - 'a')) {
                return 0;
            } else {
                u |= 1 << (c - 'a');
            }
        }
        if (c >= 'A' && c <= 'Z') {
            if (u & 1 << (c - 'A')) {
                return 0;
            } else {
                u |= 1 << (c - 'A');
            }
        }
    }
    return 1;
}

int main()
{
    vector<string> s = {"hello world", "Binlong Li", "special"};
    
    for (uint i = 0; i < s.size(); i++) {
        cout << s[i] << " is unique ? " << checkUnique(s[i]) << endl;
    }
    return 0;
}