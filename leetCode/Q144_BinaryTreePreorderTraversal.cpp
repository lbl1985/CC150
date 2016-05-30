vector<int> preorderTraversal(TreeNode* root) {
    vector<int> res;
    if(root == NULL) return res;
    
    stack<TreeNode*> s;
    s.push(root);
    while(!s.empty()){
        TreeNode* r = s.top();
        res.push_back(r->val);
        s.pop();
        if(r->right) {
            s.push(r->right);
        }
        if(r->left) {
            s.push(r->left);
        }
    }
    return res;
}