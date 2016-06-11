// Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.

// Calling next() will return the next smallest number in the BST.

// Note: next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree. 

class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        TreeNode* n = root;
        if(NULL == root) return;
        
        while(n->left != NULL){
            s.push(n);
            n = n->left;
        }
        s.push(n);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !s.empty();
    }

    /** @return the next smallest number */
    int next() {
        TreeNode* n = s.top();
        s.pop();
        int res = n->val;
        if(n->right != NULL){
            n = n->right;
            while(n->left != NULL){
                s.push(n);
                n = n->left;
            }
            s.push(n);
        }
        return res;
    }
private:
    stack<TreeNode *> s;
};