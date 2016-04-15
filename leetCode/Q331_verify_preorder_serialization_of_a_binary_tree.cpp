// One way to serialize a binary tree is to use pre-order traversal. When we encounter a non-null node, we record the node's value. If it is a null node, we record using a sentinel value such as #.
//      _9_
//     /   \
//    3     2
//   / \   / \
//  4   1  #  6
// / \ / \   / \
// # # # #   # #
// 
// 
// For example, the above binary tree can be serialized to the string "9,3,4,#,#,1,#,#,2,#,6,#,#", where # represents a null node. 
// 
// Given a string of comma separated values, verify whether it is a correct preorder traversal serialization of a binary tree. Find an algorithm without reconstructing the tree.
// 
// Each comma separated value in the string must be either an integer or a character '#' representing null pointer.
// 
// You may assume that the input format is always valid, for example it could never contain two consecutive commas such as "1,,3".
// 
// Example 1:
// "9,3,4,#,#,1,#,#,2,#,6,#,#"
//  Return true
// 
// Example 2:
// "1,#"
//  Return false
// 
// Example 3:
// "9,#,#,1"
//  Return false
// 
// class Solution {
// public:
//     bool isValidSerialization(string preorder) {
//         
//     }
// };
// 
// Author: Binlong Li
// Date:   04/13/2016
// Finish: 04/14/2016

#include "..\inc\utils.h"
#include <string>
#include <stack>

using namespace std;
bool isValidSerialization(string preorder)
{
	int ps = 0;
	string cacheStr = "";
	string substr = "";
	stack<string> ss;
	int len = preorder.length();
	bool initial = true;

    if (preorder.find(",") == string::npos) {
        if (preorder.compare("#") == 0) {
            return true;
        } else {
            return false;
        }        
    }

	for(int i = 0; i < len; i++){		
		if(preorder[i] == ',' || i == len - 1){
			int len = i - ps;
			substr = preorder.substr(ps, len);			
            if (!initial) {
                if (cacheStr.compare("") == 0) {
                    if (!ss.empty()) {
                        // cout << "pop" << ss.top() << endl;
                        ss.pop();
                    } else {
                        return false;
                    }
                } else {
                    ss.push(cacheStr);
                    // cout << "push" << cacheStr << endl;
                }
            }				
			if(substr.compare("#")){
				cacheStr = substr;
			} else {
				cacheStr = "";
			}
            initial = false;
			ps = i + 1;
		}
	}

	if (cacheStr.compare("") != 0){
		return false;
	}

	if(!ss.empty()){
		return false;
	}

	return true;
}

int Q331_verify_preorder_serialization_of_a_binary_tree()
{
	printf("Print Q331_verify_preorder_serialization_of_a_binary_tree inside");
	string st1("9,3,4,#,#,1,#,#,2,#,6,#,#");
	bool rt1 = isValidSerialization(st1);
	cout << st1 << " is binary tree? " << (rt1 ? "Yes" : "No") << endl;

    string st2("1");
    cout << st2 << " is binary tree?" << (isValidSerialization(st2) ? "Yes" : "No") << endl;

    string st3("#");
    cout << st3 << " is binary tree?" << (isValidSerialization(st3) ? "Yes" : "No") << endl;
	return 0;
}
