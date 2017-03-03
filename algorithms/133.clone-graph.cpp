/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    // DFS recursive approach : O(n)
    unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> hash;
    
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (node == nullptr)  
            return node;
        
        // init
        while (hash.find(node) == hash.end()){
            hash[node] = new UndirectedGraphNode(node->label);
            for (UndirectedGraphNode* nn : node->neighbors)
                (hash[node]->neighbors).push_back(cloneGraph(nn));
        }
        return hash[node];
    }
};
