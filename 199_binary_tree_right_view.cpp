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
    vector<int> rightSideView(TreeNode* root) {
        if (NULL == root) {
            return vector<int>();
        }
        
        vector<TreeNode*> one_layer, two_layer;
        vector<TreeNode*> &cur_layer = one_layer, &next_layer = two_layer;
        vector<int> res;
        cur_layer.push_back(root);
        while (cur_layer.size() > 0) {
            res.push_back(cur_layer.back()->val);
            for(int i = 0; i < cur_layer.size(); i ++) {
                if (cur_layer[i]->left) {
                    next_layer.push_back(cur_layer[i]->left);
                }
                
                if (cur_layer[i]->right) {
                    next_layer.push_back(cur_layer[i]->right);
                }
            }
            
            std::swap(cur_layer, next_layer);
            next_layer.clear();
        }
        return res;
    }
};