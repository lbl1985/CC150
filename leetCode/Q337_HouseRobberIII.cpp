// The thief has found himself a new place for his thievery again. There is only one entrance to this area, called the "root." Besides the root, each house has one and only one parent house. After a tour, the smart thief realized that "all houses in this place forms a binary tree". It will automatically contact the police if two directly-linked houses were broken into on the same night. 

// Determine the maximum amount of money the thief can rob tonight without alerting the police. 

// Example 1:

//      3
//     / \
//    2   3
//     \   \ 
//      3   1

// Maximum amount of money the thief can rob = 3 + 3 + 1 = 7. 

// Example 2:

//      3
//     / \
//    4   5
//   / \   \ 
//  1   3   1

// Maximum amount of money the thief can rob = 4 + 5 = 9. 

// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//  * };
//  */
// class Solution {
// public:
//     int rob(TreeNode* root) {
        
//     }
// };
// Authoer: Binlong Li
// Date: 05/20/2016
// Finish: 05/20/2016
// This is a good question. I have finished it through discussion from leetcode...

#include "..\inc\utils.h"

#include <utility>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

pair<int, int> help(TreeNode* root)
{
	if(NULL == root) {
		return {0, 0};
	}

	auto leftMoney = help(root->left);
	auto rightMoney = help(root->right);

	return {root->val + leftMoney.second + rightMoney.second, 
			max(leftMoney.first, leftMoney.second) + 
			max(rightMoney.first, rightMoney.second)
			};

}

int rob(TreeNode* root)
{
	pair<int, int> h = help(root);
	return max(h.first, h.second);
}

int Q337_HouseRobberIII()
{
	printf("inside of Q337_HouseRobberIII\n");
	return 0; 
}