/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

typedef struct TreeNode Node;


struct TreeNode* constructFromPrePost(int* preorder, int preorderSize, int* postorder, int postorderSize){
    if (preorderSize <= 0 || postorderSize <= 0) return NULL;
    
    Node *root = (Node *) malloc(sizeof(Node));
    root->left = NULL;
    root->right = NULL;
    root->val = preorder[0];
    if (preorderSize == 1) return root;
    
    preorder++;
    preorderSize--;
    postorderSize--;
    int i = 0;
    while (preorder[0] != postorder[i]) i++;
    
    root->left = constructFromPrePost(preorder, i + 1, postorder, i + 1);
    root->right = constructFromPrePost(preorder + i + 1, preorderSize - i - 1, postorder + i + 1, postorderSize - i - 1);
    
    return root;
}