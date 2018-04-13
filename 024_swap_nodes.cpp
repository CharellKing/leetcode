class Solution {
public:
	ListNode* swapPairs(ListNode* head) {
		if (NULL == head) {
			return head;
		}
		
		ListNode *prev = NULL, *cur = head, *next = cur->next;
		while (cur && next) {			
			ListNode* tmp = next->next;
			if (prev) {
				prev->next = next;
			} else {
				head = next;
			}
			next->next = cur;
			cur->next = tmp;
			prev = cur;
			cur = tmp;
			if (NULL == cur) {
				next = NULL;
			} else {
				next = cur->next;
			}
		}
		return head;		
	}
};
