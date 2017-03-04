/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (head == nullptr)  
            return nullptr;
            
        // 01. initialize the hash table & head node
        unordered_map<RandomListNode*, RandomListNode*> hash;
        RandomListNode *cur = head;
        hash[nullptr] = nullptr;
        hash[cur] = new RandomListNode(cur->label);
        
        // 02. add all nodes through next pointers
        while (cur && cur->next){
            hash[cur->next] = new RandomListNode(cur->next->label);
            hash[cur]->next = hash[cur->next];
            cur = cur->next;
        }
        
        // 03. copy the random table
        cur = head;
        while (cur){
            hash[cur]->random = hash[cur->random];
            cur = cur->next;
        }
        
        return hash[head];
    }
};
