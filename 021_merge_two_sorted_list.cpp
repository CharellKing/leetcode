class Solution {
public:
	void push_node(ListNode*& head, ListNode*& tail, ListNode* node) {
		if (NULL == head) {
			head = node;
			tail = node;
		} else {
			tail->next = node;
			tail = tail->next;
		}
	}

	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		if (NULL == l1) {
			return l2;
		}
		
		if (NULL == l2) {
			return l1;
		}

		ListNode *head = NULL, *tail = NULL;
		while (l1 && l2) {
			if (l1->val < l2->val) {
				ListNode* tmp = l1;
				push_node(head, tail, tmp);
				l1 = l1->next; 
			} else if (l1->val > l2->val) {
				ListNode* tmp = l2;
				push_node(head, tail, tmp);
				l2 = l2->next;
			} else {
				ListNode* tmp = l2;
				push_node(head, tail, tmp);
				l2 = l2->next;
				
				tmp = l1;
				push_node(head, tail, tmp);
				l1 = l1->next;
			}
		}

		if (l1) {
			tail->next = l1;
		} else if (l2) {
			tail->next = l2;
		}
		return head;
	}
};
