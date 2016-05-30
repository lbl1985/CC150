vector<int> inorderTraversal(TreeNode* root) {
    vector<int> res;
    if(root == NULL) return res;
    stack<TreeNode*> s;
    TreeNode* r;
    while(true) {
        while(root) {
            s.push(root);
            root = root->left;
        }
        if(s.empty()){
            break;
        }
        r = s.top();
        res.push_back(r->val);
        s.pop();
        root = r->right;
    }
    return res;
}