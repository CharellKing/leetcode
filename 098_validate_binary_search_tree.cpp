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
    bool is_valid_bst(TreeNode* root, long long int begin, long long int end) {
        if (NULL == root) {
            return true;
        }    
        
        if (root->val < begin || root->val > end) {
            return false;
        }
        
        if (false == is_valid_bst(root->left, begin, ((long long int)(root->val)) - 1)) {
            return false;
        }
        
        if (false == is_valid_bst(root->right, ((long long int)(root->val)) + 1, end)) {
            return false;
        }
        return true;
    }
    
    bool isValidBST(TreeNode* root) {
        return is_valid_bst(root, INT_MIN, INT_MAX);
    }
};
