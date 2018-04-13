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
    int len(ListNode* head) {
        int size = 0;
        while (head) {
            size ++;
            head = head->next;
        }
        return size;
    }
    
    ListNode* rotateRight(ListNode* head, int k) {
        int size = len(head);
        if (size <= 0) {
            return NULL;
        }
        
        k = k % size;
        k = size - k;
        if (k == size) {
            return head;
        }
        ListNode *tail = NULL, *cur = head;
        for(int i = 0; i < k; i ++) {
            tail = cur;
            cur = cur->next;
        }
        
        if (tail == NULL) {
            return head;
        }
        
        ListNode* new_head = cur;
        while (cur->next) {
            cur = cur->next;
        }
        
        cur->next = head;
        head =new_head;
        tail->next = NULL;
        return head;
    }
};
