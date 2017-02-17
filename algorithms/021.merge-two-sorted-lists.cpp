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
	// ========================= Recursive solution ============================
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        // 00. case of one list is empty
        if (l1 == nullptr)  return l2;
        if (l2 == nullptr)  return l1;
        
        //01. other cases, choose the smaller value to connect
        if (l1->val > l2->val){
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
        else{
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
    }

	// ========================= Iterative Solution ============================
    ListNode* mergeTwoLists_(ListNode* l1, ListNode* l2) {
        // 00. initialization Variables
        ListNode *p1 = l1, *p2 = l2, *result = nullptr, *tail = nullptr;
        ListNode **target = nullptr;
        
        // 01. loop
        while(p1 != nullptr || p2 != nullptr){
            if (p1 == nullptr)      target = &p2;
            else if (p2 == nullptr) target = &p1;
            else if (p1->val > p2->val) target = &p2;
            else                        target = &p1;
            
            // 02. push the target & move
            if (result == nullptr)
                tail = result = *target;
            else{
                tail->next = *target;
                tail = tail->next;
            }
            *target = (*target)->next;
        }
        return result;
    }
};
