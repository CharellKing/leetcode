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
    struct Node {
        Node() {
        }
        
        Node(const vector<int>& nums, int sum, TreeNode* node):nums(nums), sum(sum), node(node) {
        }
        
        vector<int> nums;
        int sum;
        TreeNode* node;
    };
    
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if (NULL == root) {
            return vector<vector<int>>();
        }
        
        vector<Node> one, two;
        vector<Node> &cur_layer = one, &next_layer = two;
        vector<vector<int>> ret;
        cur_layer.push_back(Node(vector<int>(1, root->val), root->val, root));
        while(cur_layer.size() > 0) {
            for(int i = 0; i < cur_layer.size(); i ++) {
                if (cur_layer[i].node->left) {
                    next_layer.push_back(cur_layer[i]);
                    next_layer.back().nums.push_back(cur_layer[i].node->left->val);
                    next_layer.back().sum += cur_layer[i].node->left->val;
                    next_layer.back().node = cur_layer[i].node->left;
                    
                }
                
                if (cur_layer[i].node->right) {
                    next_layer.push_back(cur_layer[i]);
                    next_layer.back().nums.push_back(cur_layer[i].node->right->val);
                    next_layer.back().sum += cur_layer[i].node->right->val;
                    next_layer.back().node = cur_layer[i].node->right;                    
                }
                
                if (cur_layer[i].node->left == NULL && cur_layer[i].node->right == NULL) {
                    if (cur_layer[i].sum == sum) {
                        ret.push_back(cur_layer[i].nums);
                    }
                }
            }
            swap(cur_layer, next_layer);
            next_layer.clear();
        }
        return ret;
    }
};
