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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (NULL == headA || NULL == headB) {
            return NULL;
        }
        
        int len_a = length(headA);
        int len_b = length(headB);
        int diff = abs(len_a - len_b);
        
        // 左对齐
        while (diff > 0) {
            if (len_a > len_b) headA = headA->next;
            if (len_a < len_b) headB = headB->next;
            diff --;
        }
        
        
        while (headA) {
            if (headA == headB) {
                return headA;
            }
            headA = headA->next;
            headB = headB->next;
        }
        return NULL;
    }
    
    int length(ListNode* head) {
        int len = 0;
        while (head) {
            head = head->next;
            len ++;
        }
        return len;
    }
};