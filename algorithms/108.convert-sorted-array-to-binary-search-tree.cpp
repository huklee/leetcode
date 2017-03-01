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
    TreeNode* arr2BST(vector<int>& nums, int s, int e){
        // base case
        if (s > e)  return nullptr;
        
        // recursive case
        int mid = (s + e)/2;
        TreeNode* root = new TreeNode (nums[mid]);
        root->left = arr2BST(nums, s, mid - 1);
        root->right = arr2BST(nums, mid + 1, e);
        return root;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.size() == 0)
            return nullptr;
        return arr2BST(nums, 0, nums.size() - 1);    
    }
};
