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
	// swap the pointers of list pair
    ListNode* swapPairs(ListNode* head) {
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
