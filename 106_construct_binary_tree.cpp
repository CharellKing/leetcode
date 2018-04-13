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
    TreeNode* build_tree(vector<int>& postorder, int& i, vector<int>& inorder, int begin, int end) {
        if (begin > end) {
            return NULL;
        }
        
        TreeNode* root = new TreeNode(postorder[i]);
        int j = begin;
        for(j = begin; j <= end; j ++) {
            if (inorder[j] == postorder[i]) {
                break;
            }
        }
        
        i --;
        root->right = build_tree(postorder, i, inorder, j + 1, end);
        root->left = build_tree(postorder, i, inorder, begin, j - 1);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.size() <= 0 || postorder.size() <= 0) {
            return NULL;
        }
        
        int i = postorder.size() - 1;
        return build_tree(postorder, i, inorder, 0, inorder.size() - 1);
    }
};
