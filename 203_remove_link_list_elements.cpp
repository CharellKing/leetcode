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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *prior = NULL, *cur = head;
        while (cur) {
            if (cur->val == val) {
                if (NULL == prior) {
                    head = cur->next;
                } else {
                    prior->next = cur->next;
                }
                ListNode* tmp = cur;
                cur = cur->next;
                delete tmp;
            } else {
                prior = cur;
                cur = cur->next;
            }
        }
        return head;
    }
};