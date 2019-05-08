// Solution 1 : inorder, recursive, O(n)
bool isValidBST(TreeNode* root) {
    TreeNode* pre = NULL;
    return isValid(root, pre);
}

bool isValid(TreeNode* root, TreeNode* &pre){
    if(!root) return true;
    if(!isValid(root->left, pre)) return false;
    if(pre && root->val <= pre->val) return false;
    pre = root;
    return isValid(root->right, pre);
}

//Solution 2 : inorder, iterative, O(n)
bool isValidBST(TreeNode* root) {
    stack<TreeNode*>s;
    TreeNode* pre = NULL;
    while(root || !s.empty()){
        while(root){
            s.push(root);
            root = root->left;
        }
        root = s.top();
        s.pop();
        if(pre && root->val <= pre->val) return false;
        pre = root;
        root = root->right;
    }
    return true;
}
// Solution 3:
bool isValidBST(TreeNode* root) {
    if(!root) return true;
    if(!isValid(root->left, root->val, true) || !isValid(root->right, root->val, false)) return false;
    return isValidBST(root->left) && isValidBST(root->right);
}

bool isValid(TreeNode* root, int bound, bool isLeft){
    return !root || (isLeft ? root->val < bound : root->val > bound ) && isValid(root->left, bound, isLeft) && isValid(root->right, bound, isLeft);
}
