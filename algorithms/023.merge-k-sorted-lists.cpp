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

	// Brute-Force approach : O(nk^2)
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // edge case
        if (lists.size() == 0)
            return nullptr;
            
        ListNode* prev = nullptr, *head = nullptr;
        ListNode** cur = nullptr;
        
        // find the first not-nullptr elem
        for (int i=0; i < lists.size(); i++){
            if (lists[i] != nullptr){
                cur = &lists[i];
                break;
            }
        }
        
        while ((cur != nullptr && *cur != nullptr) || prev != nullptr){
            // pick a minimum
            for (int i=0; i < lists.size(); i++){
                if (lists[i] != nullptr){
                    if (*cur == nullptr || (*cur)->val > lists[i]->val)
                        cur = &lists[i];
                }
            }
                
            
            // prev -> cur
            if (prev != nullptr)
                prev->next = *cur;
            prev = *cur;
            
            if (head == nullptr)
                head = *cur;
                
            if (*cur != nullptr)
                *cur = (*cur)->next;
        }
        return head;
    }
};
