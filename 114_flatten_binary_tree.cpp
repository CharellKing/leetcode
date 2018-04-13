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
    void to_list(TreeNode* root, TreeNode*& begin, TreeNode*& end) {
        if (NULL == root) {
            begin = end = NULL;
            return;
        }

        TreeNode *left_begin = NULL, *left_end = NULL, *right_begin = NULL, *right_end = NULL;
        to_list(root->left, left_begin, left_end);
        to_list(root->right, right_begin, right_end);
        
        begin = end = root;
        if (left_begin) {
            begin->right = left_begin;
            left_end->right = right_begin;
            end = left_end;
        }

        if (right_begin) {
            right_end->right = NULL;
            end = right_end;
        }
        root->left = NULL;
    }
    
    void flatten(TreeNode* root) {
        TreeNode *begin = root, *end = root;
        to_list(root,  begin, end);
        cout << "hello2" << endl;
    }
};
