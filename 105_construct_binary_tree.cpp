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
    TreeNode* build_tree(vector<int>& preorder, int& i, vector<int>& inorder, int begin, int end) {
        if (begin > end) {
            return NULL;
        }
        
        TreeNode* root = new TreeNode(preorder[i]);
        int j = begin;
        for(j = begin; j <= end; j ++) {
            if (inorder[j] == preorder[i]) {
                break;
            }
        }
        i ++;
        root->left = build_tree(preorder, i, inorder, begin, j - 1);
        root->right = build_tree(preorder, i, inorder, j + 1, end);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() <= 0 || inorder.size() <= 0) {
            return NULL;
        }
        
        int i = 0;
        return build_tree(preorder, i, inorder, 0, inorder.size() - 1);
    }
};
