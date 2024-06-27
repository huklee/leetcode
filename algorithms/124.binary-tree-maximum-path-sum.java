class TreeNode {
	int val;
	TreeNode left;
	TreeNode right;

	TreeNode(int x) {
		val = x;
		left = null;
		right = null;
	}
}

public class Solution {
	// Check only root-including max from root to leafs.
	// 01. Divide & Conquer : average O(nlogn)
	public int maxPathDFS(TreeNode root) {
		if (root == null) {
			return 0;
		}
		return root.val + Math.max(maxPathDFS(root.left), maxPathDFS(root.right));
	}

	public int maxPathSumDNC(TreeNode root) {
		if (root == null) {
			return 0;
		} else if (root.left == null && root.right == null) {
			return root.val;
		}

		// root_max : max path including root
		int root_max = root.val;
		if (root.left != null) {
			root_max = Math.max(root_max, root_max + maxPathDFS(root.left));
		}
		if (root.right != null) {
			root_max = Math.max(root_max, root_max + maxPathDFS(root.right));
		}

		// global_max : including left_max / right_max
		int g_max = root_max;
		if (root.left != null) {
			g_max = Math.max(g_max, maxPathSumDNC(root.left));
		}
		if (root.right != null) {
			g_max = Math.max(g_max, maxPathSumDNC(root.right));
		}

		return g_max;
	}

	// 02. one traverse solution : O(n)
	// During the travere, constanly update the global max to check all local max.
	int global_max;

	public int solve_(TreeNode root) {
		if (root == null) {
			return 0;
		}

		int left_max = solve_(root.left);
		int right_max = solve_(root.right);
		global_max = Math.max(root.val + left_max + right_max, global_max);
		global_max = Math.max(root.val + left_max, global_max);
		global_max = Math.max(root.val + right_max, global_max);
		global_max = Math.max(root.val, global_max);
		return Math.max(root.val + Math.max(left_max, right_max), root.val);
	}

	public int maxPathSumOneTraverse(TreeNode root) {
		if (root == null) {
			return 0;
		}
		global_max = Integer.MIN_VALUE;
		solve_(root);
		return global_max;
	}

	public static void main(String[] args) {
		Solution solution = new Solution();

		// Test case
		TreeNode root = new TreeNode(-10);
		root.left = new TreeNode(9);
		root.right = new TreeNode(20);
		root.right.left = new TreeNode(15);
		root.right.right = new TreeNode(7);

		System.out.println("Maximum Path Sum: " + solution.maxPathSumDNC(root)); // Output: 42
		System.out.println("Maximum Path Sum with Trick: " + solution.maxPathSumOneTraverse(root)); // Output: 42
	}
}
