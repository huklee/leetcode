/**
 * Definition for singly-linked list.
 * public class ListNode {
 *	 int val;
 *	 ListNode next;
 *	 ListNode() {}
 *	 ListNode(int val) { this.val = val; }
 *	 ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *	 int val;
 *	 TreeNode left;
 *	 TreeNode right;
 *	 TreeNode() {}
 *	 TreeNode(int val) { this.val = val; }
 *	 TreeNode(int val, TreeNode left, TreeNode right) {
 *		 this.val = val;
 *		 this.left = left;
 *		 this.right = right;
 *	 }
 * }
 */
public class Solution {
	private TreeNode convertListToBST(List<ListNode> list, int start, int end) {
		// base case
		if (start > end) {
			return null;
		}

		// recursive case
		int mid = (start == end - 1) ? end : (start + end) / 2;
		TreeNode root = new TreeNode(list.get(mid).val);
		root.left = convertListToBST(list, start, mid - 1);
		root.right = convertListToBST(list, mid + 1, end);
		return root;
	}

	public TreeNode sortedListToBST(ListNode head) {
		// edge case
		if (head == null) {
			return null;
		}

		List<ListNode> list = new ArrayList<>();
		for (ListNode current = head; current != null; current = current.next){
			list.add(current);
		}
		return convertListToBST(list, 0, list.size() - 1);
	}
}
