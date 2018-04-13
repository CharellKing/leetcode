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
    ListNode* reverseList(ListNode* head) {
        if (NULL == head) {
            return NULL;
        }
        
        ListNode *prior = NULL, *cur = head, *next = head->next;
        while (cur) {
            cur->next = prior;
            prior = cur;
            cur = next;
            if (cur) {
                next = cur->next;
            }
        }
        return prior;
    }
};
