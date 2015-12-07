// Implement a method to perform basic string compression using the counts of 
// repeated characters. For example, the string aabcccccccaaa would become a2b1c8a3
// . If the "Compressed" string would not become smaller than the original string, 
// your method should return the original string.
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef unsigned int uint;

void compressStr(string* str)
{

    if (str == nullptr || (*str).size() == 0) {
        return;
    }

    string s, stemp;
    char c, lastC = (*str)[0], cCount = 1;
    for (uint i = 1; i < (*str).size(); i++) {
        c = (*str)[i];
        if (c == lastC) {
            cCount++;
        } else {     
            s.push_back(lastC);            
            s.append(std::to_string(cCount));   
            //s += lastC + cCount;
            lastC = c;
            cCount = 1;
        }
    }
    s.push_back(c);
    s.append(std::to_string(cCount));

    if (s.size() < (*str).size())
        *str = s;
}

int main()
{
    vector<string> strArr = { "aabccccccccaaa", "hello", "test" };
    for (uint i = 0; i < strArr.size(); i++) {
        cout << "compress " << strArr[i] << " to be: ";
        compressStr(&strArr[i]);
        cout << strArr[i] << endl;
    }

    return 0;
}

