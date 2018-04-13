/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverse_list(ListNode* cur_node, ListNode*& head) {
        if (NULL == cur_node->next) {
            head = cur_node;
            return cur_node;
        }
        
        ListNode* prior = reverse_list(cur_node->next, head);
        prior->next = cur_node;
        return cur_node;
    }
    
    ListNode* reverseList(ListNode* head) {
        if (NULL == head) {
            return NULL;
        }
        
        ListNode* tail = reverse_list(head, head);
        tail->next = NULL;
        return head;
    }
};
