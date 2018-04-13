/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect_parent(TreeLinkNode* root, TreeLinkNode* parent) {
        if (NULL == root) {
            return;
        }
        
        root->next = parent;
        connect_parent(root->left, root);
        connect_parent(root->right, root);
    }
    
    TreeLinkNode* get_next_node(TreeLinkNode* node, int layer) {
        int k = layer;
        TreeLinkNode* tmp = node;
        while(node->next && node->next->right == node) {
            node = node->next;
            k --;
        }
        
        node = node->next;
        if (node) {
            node = node->right;
        }
        while(k < layer && node) {
            node = node->left;
            k ++;
        }
        return (node == tmp ? NULL : node);
    }
    
    void horizon_connect(TreeLinkNode* root, int layer) {
        if (root) {
            horizon_connect(root->left, layer + 1);
            horizon_connect(root->right, layer + 1);
            root->next = get_next_node(root, layer);
        }
    }
    
    void connect(TreeLinkNode *root) {
        connect_parent(root, NULL);
        horizon_connect(root, 0);
    }
};
