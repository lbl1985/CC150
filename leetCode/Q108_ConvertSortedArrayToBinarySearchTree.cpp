TreeNode* createTree(vector<int>& nums, int left, int right)
{
    if(left > right){
        return NULL;
    } 
    int mid = (left + right) / 2;
    TreeNode* res = new TreeNode(nums[mid]);
    res->left = createTree(nums, left, mid - 1);
    res->right = createTree(nums, mid + 1, right);
    return res;
}

TreeNode* sortedArrayToBST(vector<int>& nums) {
    int n = (int)nums.size();
    return createTree(nums, 0, n - 1);
    
    
}