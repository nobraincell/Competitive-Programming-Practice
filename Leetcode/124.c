/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int max(int x, int y) {
    return (x > y ? x : y);
}

int solve(struct TreeNode* root, int *val) {
    if (!root) return 0;
    
    int leftSum = solve(root->left, val);
    int rightSum = solve(root->right, val);
    *val = max(*val, max(root->val, leftSum + rightSum + root->val));
    
    return max(0, max(leftSum, rightSum) + root->val);
}


int maxPathSum(struct TreeNode* root){
    int val = INT_MIN;
    solve(root, &val);
    return val;
}

/*
Runtime: 24 ms, faster than 53.79% of C online submissions for Binary Tree Maximum Path Sum.
Memory Usage: 13.5 MB, less than 79.55% of C online submissions for Binary Tree Maximum Path Sum.
*/