int kthSmallest(TreeNode* root, int k) {
    int c = 0;
    bool found = false;
    int res = 0;
    inOrderTraverse(root, k, c, found, res);
    return res;
}
void inOrderTraverse(TreeNode* root, int k, int& c, bool& found, int& res)
{
    if(root == NULL) return;
    if(root->left) inOrderTraverse(root->left, k, c, found, res);
    if(found == true) {
        return;
    } else{
        c++;
    }
    if (c == k) {
        res = root->val;
        found = true;
        return;
    }
    if(root->right) inOrderTraverse(root->right, k, c, found, res);
}