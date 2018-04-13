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
    void build_tree_sum(TreeNode* root, int num, int& sum) {
        if (NULL == root->left && NULL == root->right) {
            sum += num * 10 + root->val;
        }
        
        num = num * 10 + root->val;
        if (root->left) {
            build_tree_sum(root->left, num, sum);
        }
        
        if (root->right) {
            build_tree_sum(root->right, num, sum);
        }
    }
    
    int sumNumbers(TreeNode* root) {
        if (NULL == root) {
            return 0;
        }
        
        int sum = 0, num = 0;
        build_tree_sum(root, num, sum);
        return sum;
    }
};