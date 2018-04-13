/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    int length(const ListNode* head) {
        int len = 0;
        while (head) {
            len ++;
            head = head->next;
        }
        return len;
    }
    
    const ListNode* get_mid_node(const ListNode* begin, int mid) {
        for(int i = 0; i < mid; i ++) {
            begin = begin->next;
        }
        return begin;
    }
    
    TreeNode* build_tree(const ListNode* begin, int len) {
        if (len <= 0) {
            return NULL;
        }
        
        int mid = len >> 1;
        const ListNode* mid_node = get_mid_node(begin, mid);
        TreeNode* root = new TreeNode(mid_node->val);
        root->left = build_tree(begin, mid);
        root->right = build_tree(mid_node->next, len - mid - 1);
        return root;
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
        int len = length(head);
        return build_tree(head, len);
    }
};
