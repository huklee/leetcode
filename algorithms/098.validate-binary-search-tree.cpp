/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// recursive solution : O(n)
class Solution {
public:
	// ======================= Child comparison approach ===========================
	bool isValidBSTinfo_(TreeNode* root, TreeNode* minNode, TreeNode* maxNode){
		// 00. base cases
		if (root == nullptr)
			return true; 
	
		// 01. edge cases : in case one subtree is invalid tree 
		// if (minNode->val >= root->val && minNode)		// Wrong!
		bool isLeftInvalid = minNode && minNode->val >= root->val;
		bool isRightInvalid = maxNode && maxNode->val <= root->val;
		if (isLeftInvalid || isRightInvalid)
			return false;

		// 02. other cases
		bool isLeftValid = isValidBSTinfo_(root->left, minNode, root);
		bool isRightValid = isValidBSTinfo_(root->right, root, maxNode);
		return isLeftValid && isRightValid;
	}

	// ======================= Root comparison approach ============================
	class BSTinfo{
	public:
		bool isValid;
		int maxVal;
		int minVal;
		BSTinfo(bool is, int minV, int maxV) : isValid(is), maxVal(maxV), minVal(minV){};
	};

	BSTinfo isValidBSTinfo(TreeNode* root){
		// 00. edge & base cases
		if (root == nullptr)
			return BSTinfo(true, -1, -1);
		if (root->left == nullptr && root->right == nullptr)
			return BSTinfo(true, root->val, root->val);

		// 01. in case one subtree is a leaf node
		if (root->left == nullptr){
			BSTinfo rInfo = isValidBSTinfo(root->right);
			if (rInfo.isValid && root->val < rInfo.minVal)
				return BSTinfo(true, root->val, rInfo.maxVal);
			return BSTinfo(false, -1, -1);
		}
		if (root->right == nullptr){
			BSTinfo lInfo = isValidBSTinfo(root->left);
			if (lInfo.isValid && lInfo.maxVal < root->val)
				return BSTinfo(true, lInfo.minVal, root->val);
			return BSTinfo(false, -1, -1);
		}

		// 02. other cases 
		BSTinfo lInfo = isValidBSTinfo(root->left);
		BSTinfo rInfo = isValidBSTinfo(root->right);
		if (lInfo.isValid && rInfo.isValid){
			if (lInfo.maxVal < root->val && root->val < rInfo.minVal)
				return BSTinfo(true, lInfo.minVal, rInfo.maxVal);
		}
		return BSTinfo(false, -1, -1);
	}

    bool isValidBST(TreeNode* root) {
        // return isValidBSTinfo(root).isValid;
        return isValidBSTinfo_(root, nullptr, nullptr);
    }
};

