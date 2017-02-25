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
    // BFS solution
    int minDepth(TreeNode* root) {
        if (root == nullptr)    return 0;
        queue<TreeNode*> q;
        q.push(root);
        int depth = 0;
        while (q.size() > 0){
            int cnt_node = q.size();
            depth++;
            for (int i=0; i < cnt_node; i++){
                TreeNode* p = q.front();
                q.pop();
                if (p->left == nullptr && p->right == nullptr) 
                    return depth;
                if (p->left)    q.push(p->left);
                if (p->right)   q.push(p->right);
            }
        }
        return depth;
    }
};
