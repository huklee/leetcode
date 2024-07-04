/**
 * Definition for singly-linked list.
 * class ListNode {
 *	 int val;
 *	 ListNode next;
 *	 ListNode(int x) {
 *		 val = x;
 *		 next = null;
 *	 }
 * }
 */
public class Solution {
	// Using two point solution: TC is O(n), SC is O(1)
	// if distance(fast) - distance(slow) = length(loop), then slow and fast will meet
	public boolean hasCycle(ListNode head){
		if (head == null)
			return false;

		ListNode slow = head, fast = head;
		while (true){
			if (fast.next == null || fast.next.next == null)
				break;

			slow = slow.next;
			fast = fast.next.next;
			if (slow == fast && slow != null)
				return true;
		}
		return false;
	}

	// Hashset solution: TC is O(n), SC is O(n) as well.
	public boolean hasCycleUsingSet(ListNode head) {
		if (head == null)
			return false;
			
		HashSet<ListNode> hashSet = new HashSet<>();
		ListNode cur = head;
		hashSet.add(cur);
		while (cur.next != null){
			if (hashSet.contains(cur.next))
				return true; 
			else
				hashSet.add(cur.next);
			cur = cur.next;
		}
		return false;
	}
}
