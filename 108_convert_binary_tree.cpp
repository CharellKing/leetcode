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
    TreeNode* build_tree(const vector<int>& nums, int begin, int end) {
        if (begin > end) {
            return NULL;    
        }
        
        int mid = (begin + end + 1) >> 1;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = build_tree(nums, begin, mid - 1);
        root->right = build_tree(nums, mid + 1, end);
        return root;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return build_tree(nums, 0, nums.size() - 1);
    }
};
