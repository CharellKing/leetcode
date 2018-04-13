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
    vector<int> inorderTraversal(TreeNode* root) {
        if (NULL == root) {
            return vector<int>();
        }
        
        stack<TreeNode*> s;
        vector<int> ret;
        s.push(root);
        while(s.size() > 0) {
            while (s.top()->left) {
                s.push(s.top()->left);
            }
            ret.push_back(s.top()->val);
            if (s.top()->right) {
                s.push(s.top()->right);
            } else {
                TreeNode* child = s.top();
                s.pop();
                if (s.size() <= 0) {
                    break;
                }
                TreeNode* parent = s.top();
                while (child == parent->right || parent->right == NULL) {
                    if (NULL == parent->right) {
                        ret.push_back(s.top()->val);
                    }
                    child = parent;
                    s.pop();
                    if (s.size() <= 0) {
                        break;
                    }
                    parent = s.top();
                }
                
                if (s.size() > 0) {
                    ret.push_back(s.top()->val);
                    s.push(s.top()->right);
                }
            }
        }
        return ret;
    }
};
