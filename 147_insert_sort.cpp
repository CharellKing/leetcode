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
    ListNode* insertionSortList(ListNode* head) {
	  if (NULL == head) {
		return NULL;
	  }


        ListNode *target = head->next, *tail = head;
        while (target) {
            ListNode *prior = NULL, *cur = head;
            while (cur != target) {
		     if (cur->val > target->val) {
		         if (NULL == prior) {
				 head = target;
			   } else {
				 prior->next = target;
		     	   }
                     ListNode* tmp = target->next;
                     target->next = cur;
                     tail->next = tmp;
                     target = tmp;
                     break;
                 }
                 prior = cur;
                 cur = cur->next;
		}
	      if (cur == target) {
			target = target->next;
			tail = tail->next;
		}
	 }
       return head;
    }
};


