class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
    	ListNode* begin = head;
    	while (begin) {
    		ListNode* forward = begin->next;
    		while (forward && forward->val == begin->val) {
    			begin->next = forward->next;
    			forward = begin->next;
    		}
    		begin = forward;
    	}
    	return head;
    }
};