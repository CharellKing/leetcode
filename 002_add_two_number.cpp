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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    	if (l1 == NULL) {
    		return l2;
    	}

    	if (l2 == NULL) {
    		return l1;
    	}

    	ListNode *head1 = l1, *head2 = l2, *prev = NULL;
    	int remain = 0;
    	while (head1 && head2) {
    		head1->val += (head2->val + remain);
    		if (head1->val >= 10) {
    			head1->val -= 10;
    			remain = 1;
    		} else {
    			remain = 0;
    		}
    		prev = head1;
    		head1 = head1->next, head2 = head2->next;
    	}

    	if (head2) {
    		prev->next = head2;
    		head1 = prev->next;
    	}

    	while (head1 && remain > 0) {
    		head1->val += remain;
    		if (head1->val >= 10) {
    			head1->val -= 10;
    			remain = 1;
    		} else {
    			remain = 0;
    		}
    		prev = head1;
    		head1 = head1->next;
    	}

    	if (remain > 0) {
    		prev->next = new ListNode(remain);
    	}

        return l1;
    }
};