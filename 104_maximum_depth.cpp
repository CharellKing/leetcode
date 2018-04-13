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
    int maxDepth(TreeNode* root) {
        if (NULL == root) {
            return 0;
        }
        vector<TreeNode*> one_nodes, two_nodes;
        vector<TreeNode*> &cur_nodes = one_nodes, &next_nodes = two_nodes;
        cur_nodes.push_back(root);
        int max_depth = 0;
        while (cur_nodes.size() > 0) {
            for(int i = 0; i < cur_nodes.size(); i ++) {
                if (cur_nodes[i]->left) next_nodes.push_back(cur_nodes[i]->left);
                if (cur_nodes[i]->right) next_nodes.push_back(cur_nodes[i]->right);
            }
            
            vector<TreeNode*>& tmp = cur_nodes;
            cur_nodes = next_nodes;
            next_nodes = tmp;
            next_nodes.clear();
            
            max_depth ++;
        }
        return max_depth;
    }
};
