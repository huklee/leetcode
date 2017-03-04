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
	// 01. Divide & Conquer : average O(nlogn)
    int max_path_DFS (TreeNode* root){
        if (root == nullptr)    return 0;
        return root->val + max(max_path_DFS(root->left), max_path_DFS(root->right));
    }

    int maxPathSum_(TreeNode* root) {
        if (root == nullptr)
            return 0;
        else if (root->left == nullptr && root->right == nullptr)
            return root->val;
            
        // root_max : max path including root
        int root_max = root->val;
        if (root->left)
            root_max = max (root_max, root_max + max_path_DFS(root->left));
        if (root->right)
            root_max = max (root_max, root_max + max_path_DFS(root->right));
            
        // global_max : including left_max / right_max
        int g_max = root_max;
        if (root->left)
            g_max = max (g_max, maxPathSum_(root->left));
        if (root->right)
            g_max = max (g_max, maxPathSum_(root->right));
        
        return g_max;
    }
   
	// 02. one traverse solution : O(n)
	int global_max;
	int solve_(TreeNode *root){
		if (root == nullptr)
			return 0;

		int left_max = solve_(root->left);
		int right_max = solve_(root->right);
		global_max = max(root->val + left_max + right_max, global_max);
		global_max = max(root->val + left_max, global_max);
		global_max = max(root->val + right_max, global_max);
		global_max = max(root->val, global_max);
		int root_max = max(root->val + max(left_max, right_max), root->val);
		return root_max;
	}

	int maxPathSum(TreeNode* root){
		if (root == nullptr)	return 0;
		global_max = -(1<<31);
		solve(root);
		return global_max;
	}
 
	// 03. one traverse solution : O(n)
	// with a trick : return non-negative value
	int global_max;
	int solve(TreeNode *root){
		if (root == nullptr)
			return 0;

		int left_max = solve(root->left);
		int right_max = solve(root->right);
		global_max = max(root->val + left_max + right_max, global_max);
		int root_max = root->val + max(left_max, right_max);
		return root_max > 0 ? root_max : 0;
	}

	int maxPathSum(TreeNode* root){
		if (root == nullptr)	return 0;
		global_max = -(1<<31);
		solve(root);
		return global_max;
	}
};
