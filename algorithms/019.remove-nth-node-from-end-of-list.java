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
 // TC=O(n), SC=O(1) Two Pointers using solution
class Solution {
	public ListNode removeNthFromEnd(ListNode head, int n) {
		// Edge case 1: head is target to remove
		if (head.next == null && n == 1)
			return null;

		ListNode toBeTail = head;
		for (int i =0; i < n; i++)
			toBeTail = toBeTail.next;

		// Edge case 2: first element removal case
		if (toBeTail == null){
			return head.next;
		}

		ListNode cur = head;
		while (toBeTail.next != null){
			cur = cur.next;
			toBeTail = toBeTail.next;
		}

		// remove operation
		cur.next = (cur.next == null) ? null : cur.next.next;
		return head;
	}
}
