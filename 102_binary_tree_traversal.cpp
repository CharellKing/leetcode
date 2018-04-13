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
    vector<int> level_nums(vector<TreeNode*>& nodes) {
        vector<int> ret;
        for(int i = 0; i < nodes.size(); i ++) {
            if (nodes[i]) {
                ret.push_back(nodes[i]->val);
            }
        }
        return ret;
    }
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (NULL == root) {
            return vector<vector<int>>();
        }
        
        vector<TreeNode*> one_nodes, two_nodes;
        vector<TreeNode*> &cur_nodes = one_nodes, &next_nodes = two_nodes;
        cur_nodes.push_back(root);
        vector<vector<int>> res;
        do {
            res.push_back(level_nums(cur_nodes));
            for(int i = 0; i < cur_nodes.size(); i ++) {
                if (cur_nodes[i]->left) {
                    next_nodes.push_back(cur_nodes[i]->left);
                }
                
                if (cur_nodes[i]->right) {
                    next_nodes.push_back(cur_nodes[i]->right);
                }
            }
            
            vector<TreeNode*>& tmp = cur_nodes;
            cur_nodes = next_nodes;
            next_nodes = tmp;
            next_nodes.clear();
        } while (cur_nodes.size() > 0);
        return res;
    }
};
