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
    vector<int> preorderTraversal(TreeNode* root) {
	  if (NULL == root) {
	      return vector<int>();
	  }


        vector<int> ret;
        stack<TreeNode*> s;
	  s.push(root);
        ret.push_back(root->val);
        while (s.size() > 0) {
		while(s.top()->left) {
			s.push(s.top()->left);
			ret.push_back(s.top()->val);
		} 


		TreeNode *child = NULL, *parent = s.top();
	while (parent && (child == parent->right || parent->right == NULL) && s.size() > 0) {
		s.pop();
		child = parent;
		if (s.size() > 0){
			parent = s.top();
		}
	}


		if (s.size() > 0) {
			s.push(parent->right);
			ret.push_back(s.top()->val);


		}
	  }
	  return ret;
    }
};


