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
    ListNode* partition(ListNode* head, int x) {
	if (NULL == head) {
		return NULL;
	}
      	ListNode *smaller_head = NULL, *smaller_tail = NULL;
	ListNode *bigger_head = NULL, *bigger_tail = NULL;  
	while(head) {
		if (head->val < x) {
			if (smaller_head == NULL) {
				smaller_head = head;
			}

			if (smaller_tail == NULL) {
				smaller_tail = head;
			} else {
				smaller_tail->next = head;
				smaller_tail = head;
			}
		} else {
			if (bigger_head == NULL) {
				bigger_head = head;
			} 

			if (bigger_tail == NULL) {
				bigger_tail = head;
			} else {
				bigger_tail->next = head;
				bigger_tail = head;
			}
		}
		head = head->next;
	}
	if (smaller_head == NULL) {
		return bigger_head;
	}
	smaller_tail->next = bigger_head;
	if (bigger_tail) {
		bigger_tail->next = NULL;
        }
	return smaller_head; 
    }
};