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
    int sumOfLeftLeaves(TreeNode* root) {
        if (NULL == root) {
            return 0;
        }
        
        int sum = 0;
        if (root->left && NULL == root->left->left && NULL == root->left->right) {
            sum += root->left->val;
        }
        
        if (root->left) {
            sum += sumOfLeftLeaves(root->left);
        }
        
        if (root->right) {
            sum += sumOfLeftLeaves(root->right);
        }
        return sum;
    }
};
