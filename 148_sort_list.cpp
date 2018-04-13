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
    ListNode* right(ListNode* head, int mid) {
	  for (int i = 0; i < mid; i ++) {
		head = head->next;
        }
        return head;
    }


    ListNode* merge(ListNode* left_begin, int left_len, ListNode* right_begin, int right_len) {
        int i = 0, j = 0;
        ListNode *merge_head = NULL, *merge_tail = NULL;
        while (i < left_len || j < right_len) {
		if (i < left_len && j < right_len) {
		    ListNode* min_node = left_begin;
                if (left_begin->val > right_begin->val) {
                    min_node = right_begin;
                    right_begin = right_begin->next;
                    j ++;
                } else {
                    i ++;
                    left_begin = left_begin->next;
                }
		    
                if (NULL == merge_head) {
                    merge_head = min_node;
                    merge_tail = min_node;
		    } else {
                    merge_tail->next = min_node;
                    merge_tail = merge_tail->next;
                }
		} else if (i < left_len) {
		    if (NULL == merge_head) {
                    merge_head = left_begin;
                  merge_tail = left_begin;
              } else {
merge_tail->next = left_begin;
                  merge_tail = merge_tail->next;
              }
              left_begin= left_begin->next;
              i ++;
           } else if (j < right_len) {
    		  if (NULL == merge_head) {
                  merge_head = right_begin;
                  merge_tail = right_begin;
              } else {
merge_tail->next = right_begin;
                  merge_tail = merge_tail->next;
              }
              j ++;
              right_begin = right_begin->next;
	     }
        }
        merge_tail->next = NULL;
        return merge_head;
    }


    ListNode* sort(ListNode* head, int len) {
        if (len <= 1) {
            return head;
        }
        
        int mid = len >> 1;
        ListNode* left_head = head;
        ListNode* right_head = right(head, mid);
        left_head = sort(left_head, mid);
        right_head = sort(right_head, len - mid);
        return merge(left_head, mid, right_head, len - mid);
    }


    


    int length(ListNode* head) {
        int len = 0;
	  while (head) {
            head = head->next;
            len ++;
        }
        return len;
    }


    ListNode* sortList(ListNode* head) {
    	  if (NULL == head) {
		return NULL;
  }
  int len = length(head);
  return sort(head, len);
    }
};




