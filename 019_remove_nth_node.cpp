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
    ListNode* remove_node(ListNode* head, ListNode* cur, int n, int& i) {
        if (NULL == cur) {
            i = 0;
        } else {
            ListNode* next = remove_node(head, cur->next, n, i);
            i ++;
            if (i == n) {
                delete cur;
                cur = next;
                cout << "hello" << endl;
            } else {
                cur->next = next;
            }
        }
        return cur;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (NULL == head) {
            return head;
        }
        int i = 0;
        return remove_node(head, head, n, i);
    }
};
