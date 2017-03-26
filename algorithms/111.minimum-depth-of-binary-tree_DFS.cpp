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
    int min_val = 0;
    // DFS solution
    int minDepth(TreeNode* root) {
        get_min_depth(root, 1);
        return min_val;
    }

    void get_min_depth(TreeNode* root, int depth){
        if (root == nullptr)                    return;
        if (min_val > 0 && depth >= min_val)    return;
        if (root->right)    
            get_min_depth(root->right, depth + 1);
        else if (root->left)   
            get_min_depth(root->left, depth + 1);
        else
            min_val = (min_val == 0 || min_val > depth) ? depth : min_val;
    }
};
