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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
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
