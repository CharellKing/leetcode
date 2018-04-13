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
    bool node_is_symmetric(TreeNode* p, TreeNode* q) {
        return (NULL == p && NULL == q) || (p && q && p->val == q->val);    
    }
    
    bool nodes_is_symmetric(const vector<TreeNode*>& nodes) {
        int i = 0, j = nodes.size() - 1;
        while (i < j) {
            if (false == node_is_symmetric(nodes[i], nodes[j])) {
                return false;
            }
            i ++;
            j --;
        }
        return true;
    }
    
    bool isSymmetric(TreeNode* root) {
        if (NULL == root) {
            return true;
        }
        
        vector<TreeNode*> one_nodes, two_nodes;
        vector<TreeNode*> &cur_nodes = one_nodes, &next_nodes = two_nodes;
        cur_nodes.push_back(root);
        while (cur_nodes.size() > 0) {
            for(int i = 0; i < cur_nodes.size(); i ++) {
                if (cur_nodes[i]) {
                    next_nodes.push_back(cur_nodes[i]->left);
                    next_nodes.push_back(cur_nodes[i]->right);
                }
            }
            if (false == nodes_is_symmetric(next_nodes)) {
                return false;
            }
            
            vector<TreeNode*>& tmp = cur_nodes;
            cur_nodes = next_nodes;
            next_nodes = tmp;
            next_nodes.clear();
        }
        return true;
    }
};
