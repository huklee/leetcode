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
    // recursive solution
    ListNode* swapPairs(ListNode* head) {
        // base case
        if (!head || !head->next)
            return head;
    
        // recursive case
        ListNode *new_head = head->next;
        head->next = swapPairs(head->next->next);
        new_head->next = head;
        return new_head;
    }

	// iterative solution
    ListNode* swapPairs_iter(ListNode* head) {
        ListNode *cur = head, *prev = nullptr;
        while (cur && cur->next){
            if(prev){
				// from the 2nd swap
                prev->next = cur->next;
                cur->next = cur->next->next;
                prev->next->next = cur;
            }
            else{
				// first swap
                head = head->next;
                cur->next = cur->next->next;
                head->next = cur;
            }
            prev = cur;
            cur = cur->next;
        }
        return head;
    }
};
