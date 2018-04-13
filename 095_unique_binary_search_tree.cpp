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
    vector<TreeNode*> build_tree(int begin, int end) {
        if (begin == end) {
            TreeNode* root = new TreeNode(begin);
            return vector<TreeNode*>(1, root);
        }
        
        if (begin > end) {
            return vector<TreeNode*>(1, NULL);
        }
        vector<TreeNode*> rets;
        for(int i = begin; i <= end; i ++) {
            vector<TreeNode*> left_sub_trees = build_tree(begin, i - 1);
            vector<TreeNode*> right_sub_trees = build_tree(i + 1, end);
            for(int j = 0; j < left_sub_trees.size(); j ++) {
                for(int k = 0; k < right_sub_trees.size(); k ++) {
                    TreeNode* root = new TreeNode(i);
                    root->left = left_sub_trees[j];
                    root->right = right_sub_trees[k];
                    rets.push_back(root);
                }
            }
        }
        return rets;
    }
    
    vector<TreeNode*> generateTrees(int n) {
        if (n <= 0) {
            return vector<TreeNode*>();
        }
        return build_tree(1, n);
    }
};
