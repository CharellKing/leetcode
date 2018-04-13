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
    ListNode* deleteDuplicates(ListNode* head) {
        if (NULL == head) {
            return NULL;
        }
        
        ListNode *prev = NULL, *cur = head;
        while (cur) {
            int count = 1;
            ListNode *next = cur->next;
            while (next && next->val == cur->val) {
                next = next->next;
                count ++;
            }
            if (count > 1) {
                if (NULL == prev) {
                    head = next;
                    cur = next;
                } else {
                    prev->next = next;
                    cur = next;
                }
            } else {
                prev = cur;
                cur = next;
            }
        }
        return head;
    }
};
