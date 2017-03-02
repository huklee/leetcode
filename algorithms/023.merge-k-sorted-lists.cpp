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
    ListNode* mergeTwoLists(ListNode* n1, ListNode* n2){
        if (n1 == nullptr)      
            return n2;
        else if (n2 == nullptr) 
            return n1;
        else if (n1->val < n2->val){
            n1->next = mergeTwoLists(n1->next, n2);
            return n1;
        }
        else{
            n2->next = mergeTwoLists(n1, n2->next);
            return n2;
        }
    }

    // Divide & Conquer approach : O(nklogk)
    ListNode* mergeKLists(vector<ListNode*>& v){
        if (v.size() == 0)
            return nullptr;
        while (v.size() > 1){
            v.push_back(mergeTwoLists(v[0], v[1]));
            v.erase(v.begin());
            v.erase(v.begin());
        }
        return v[0];
    }
    
	// Brute-Force approach : O(nk^2)
    ListNode* mergeKLists_(vector<ListNode*>& lists) {
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

