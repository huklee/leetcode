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
        ListNode *result, *tail, *t1 = l1, *t2 = l2;
        int overflow=0;
        while (t1 != NULL || t2 != NULL || overflow == 1){
            int sum=overflow;
            if (t1 != NULL) sum += t1->val;
            if (t2 != NULL) sum += t2->val;
            
            if (sum >= 10)  {
                overflow = 1;
                sum -= 10;
            }
            else
                overflow = 0;
                
            if (result == NULL){
                result = new ListNode(sum);
                tail = result;                
            }
            else{
                tail->next = new ListNode(sum);
                tail = tail->next;
            }
            
            if (t1 != NULL)   t1 = t1->next;
            if (t2 != NULL)   t2 = t2->next;
        }
        return result;
        
    }
};
