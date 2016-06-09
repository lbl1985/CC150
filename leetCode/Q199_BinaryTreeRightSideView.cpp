// Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

// For example:
//  Given the following binary tree,

//    1            <---
//  /   \
// 2     3         <---
//  \     \
//   5     4       <---



// You should return [1, 3, 4].

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if(root == NULL) return {};
        queue<TreeNode*> q;
        queue<int> layerId;
        vector<int> res;
        q.push(root);
        layerId.push(0);
        
        int prevLayer = 0;
        int curLayer = 0;
        int prevVal;
        
        while(!q.empty()){
            TreeNode* t = q.front();
            curLayer = layerId.front();
            if(curLayer != prevLayer){
                res.push_back(prevVal);
            }
            if(t->left){
                q.push(t->left);
                layerId.push(curLayer+1);
            }
            if(t->right){
                q.push(t->right);
                layerId.push(curLayer+1);
            }
            prevLayer = curLayer;
            prevVal = t->val;
            q.pop();
            layerId.pop();
        }
        res.push_back(prevVal);
        return res;
    }
};