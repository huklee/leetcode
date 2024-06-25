/*
// Definition for a Node.
class Node {
	int val;
	Node next;
	Node random;

	public Node(int val) {
		this.val = val;
		this.next = null;
		this.random = null;
	}
}
*/

public class Solution {
	public Node copyRandomList(Node head) {
		if (head == null)
			return null;

		// Initialize a map to store original node to cloned node mapping
		Map<Node, Node> map = new HashMap<>();

		// Step 1: Clone all nodes and store mapping in the map
		Node cur = head;
		while (cur != null) {
			map.put(cur, new Node(cur.val));
			cur = cur.next;
		}

		// Step 2: Adjust next and random pointers of cloned nodes
		cur = head;
		while (cur != null) {
			map.get(cur).next = map.get(cur.next);
			map.get(cur).random = map.get(cur.random);
			cur = cur.next;
		}

		Node answer = map.get(head);
		// Mark map for garbage collection
		map = null;	 
		return answer;
	}
}
