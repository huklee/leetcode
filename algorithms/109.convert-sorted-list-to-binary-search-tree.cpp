/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* convertVectorToBST(vector<ListNode*> &vl, int s, int e){
        // base case
        if (s > e)
            return nullptr;
            
        // recursive case
        int mid = (s == e - 1) ? e : (s + e)/2;
        TreeNode* t = new TreeNode(vl[mid]->val);
        t->left = convertVectorToBST(vl, s, mid - 1);
        t->right = convertVectorToBST(vl, mid + 1, e);
        return t;
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
        // edge case
        if (head == nullptr)
            return nullptr;
        
        vector<ListNode*> vl;
        for (ListNode* cur = head; cur != nullptr; cur = cur->next)
            vl.push_back(cur);
        return convertVectorToBST(vl, 0, vl.size() - 1);
    }
    

};
