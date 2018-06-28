#include "..\inc\utils.h"
#include <map>
#include <vector>

using namespace std;

string convert(string s, int numRows) {

    // firstly create the index array with pattern for string array index. 
    vector<int> index;
    for (int i = 0; i < numRows; i++) {
        index.push_back(i);
    }

    for (int i = numRows - 2; i > 0; i--) {
        index.push_back(i);
    }

    // mod will be the divided for us to get the string array index
    int mod = index.size();

    // initialize string_arr
    vector<string> string_arr;
    for (int i = 0; i < numRows; i++) {
        string_arr.push_back("");
    }
        
    // put each and every character into the designed location of the string_array.
    for (int i = 0; i < s.length(); i++) {
        
        string_arr[index[i%mod]] += s[i];
    }

    // assemble the final result.
    string res = "";
    for (int i = 0; i < numRows; i++) {
        res.append(string_arr[i]);
    }

    return res;
}

int Q006_zigzag_conversion()
{
    printf("inside of Q006_zigzag_conversion\n");
    string test1 = "PAYPALISHIRING";
    string res1 = convert(test1, 3);
    cout << test1.c_str() << endl << res1.c_str() << endl;

    
    res1 = convert(test1, 4);
    cout << test1.c_str() << endl << res1.c_str() << endl;
    
    return 0;
}