/**
 * Definition for singly-linked list.
 * public class ListNode {
 *   int val;
 *   ListNode next;
 *   ListNode() {}
 *   ListNode(int val) { this.val = val; }
 *   ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
	public ListNode reverseKGroup(ListNode head, int k) {
		ListNode cur = head;
		int count = 0;

		// find the k+1 node
		while (cur != null && count != k) { 
			cur = cur.next;
			count++;
		}
		if (count == k) { 
			cur = reverseKGroup(cur, k); 
			while (count > 0) { 
				// attach reverse from head to next chunk
				ListNode tmp = head.next;
				head.next = cur; 
				cur = head; 
				head = tmp;
				count--;
			}
			head = cur;
		}
		return head;
	}
}
