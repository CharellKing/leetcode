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
    int get_length(ListNode* head) {
        int len = 0;
        while (head) {
            head = head->next;
            len ++;
        }
        return len;
    }
    
    ListNode* partition(ListNode* head, int len) {
        ListNode*& mid_node = head;
        int mid = len >> 1;
        for(int i = 0; i + 1 < mid; i ++) {
            mid_node = mid_node->next;
        }
        ListNode* ret = mid_node->next;
        mid_node->next = NULL;
        return ret;
    }
    
    ListNode* reverse(ListNode* head) {
        ListNode *prev = NULL, *cur= head, *next = head->next;
        while (cur) {
            cur->next = prev;
            prev = cur;
            cur = next;
            if (cur) {
                next = cur->next;
            }
        }
        return prev;
    }
    
    void reorderList(ListNode* head) {
        if (NULL == head) {
            return;
        }
        
        if (NULL == head->next)  {
            return;    
        }
        
        int len = get_length(head);
        ListNode* mid = partition(head, len);
        mid = reverse(mid);
        ListNode* new_head = head;
        while (head || mid) {
            if (head) {
                if (new_head != head) {
                    new_head->next = head;
                    new_head = new_head->next;
                }
                head = head->next;
            }
            
            if (mid) {
                new_head->next = mid;
                new_head = new_head->next;
                mid = mid->next;
            }
        }
        new_head->next = NULL;
    }
};