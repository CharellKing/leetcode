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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (NULL == root) {
            return vector<vector<int>>();
        }
        
        vector<TreeNode*> one, two;
        vector<TreeNode*> &cur = one, &next = two;
        vector<vector<int>> ret;
        cur.push_back(root);
        bool is_reverse = false;
        while (cur.size() > 0) {
            ret.push_back(vector<int>());
            for(int i = 0; i < cur.size(); i ++) {
                if (cur[i]->left) {
                    next.push_back(cur[i]->left);
                }
                
                if (cur[i]->right) {
                    next.push_back(cur[i]->right);
                }
            }
            
            if (false == is_reverse) {
                for(int i = 0; i < cur.size(); i ++) {
                    ret.back().push_back(cur[i]->val);
                }
            } else {
                for(int i = cur.size() - 1; i >= 0; i --) {
                    ret.back().push_back(cur[i]->val);
                }
            }
            swap(cur, next);
            next.clear();
            is_reverse = !is_reverse;
        }
        return ret;
    }
};
