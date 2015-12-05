// 1.3 Given two strings, write a method to decide if one is a permutation of the other.
#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool isPermutation(const string* s1, const string* s2)
{
    int len1 = (*s1).length();
    int len2 = (*s2).length();
    if (len1 != len2) {
        return false;
    }

    int rec[256] = {};
    memset(rec, 0, 256 * sizeof(int));

    for (int i = 0; i < len1; i++) {
        rec[(*s1)[i]]++;
    }

    char temp;
    for (int i = 0; i < len2; i++) {
        temp = (*s2)[i];
        if (rec[temp] == 0) {
            return false;
        } else {
            rec[temp]--;
        }
    }
    return true;
}


int main()
{
    vector<string>stringArr0 = { "hello world", "Binlong", "test" };
    vector<string>stringArr1 = { "world hello", "Li", "estt1" };

    int s = stringArr0.size();
    for (int i = 0; i < s; i++) {
        bool bIsPer = isPermutation(&stringArr0[i], &stringArr1[i]);
        cout << stringArr0[i] << " and " << stringArr1[i] << " is permutation? " << bIsPer << endl;
    }

}