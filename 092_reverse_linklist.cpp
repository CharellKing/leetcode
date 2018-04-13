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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (NULL == head || m >= n) {
        	return head;
        }

        int i = 1;
        ListNode *prior = NULL, *cur = head;
        while (cur && i < m) {
        	prior = cur;
        	cur = cur->next;
        	i ++;
        }

        if (NULL == cur) {
        	return head;
        }

        ListNode *begin = cur, *end = cur, *next = cur->next;
        while (next && i < n) {
        	ListNode* tmp = next->next;
        	next->next = end;
        	end = next;
        	next = tmp;
        	i ++;
        }

        if (prior) {
        	prior->next = end;
        	begin->next = next;
        } else {
        	head = end;
        	begin->next = next;
        }
        return head;
    }
};
