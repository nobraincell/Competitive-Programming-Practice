/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

typedef struct TreeNode Node;

struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize){
    if (inorderSize == 0 || postorderSize == 0) return NULL;
    
    Node *root = (Node *) malloc(sizeof(Node));
    root->val = postorder[postorderSize - 1];
    
    int i = 0;
    while (inorder[i] != postorder[postorderSize - 1]) i++;
    root->left = buildTree(inorder, i, postorder, i);
    root->right = buildTree(inorder + i + 1, inorderSize - i - 1, postorder + i, postorderSize - i - 1);
    return root;
}