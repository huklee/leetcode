/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *	 this.val = (val===undefined ? 0 : val)
 *	 this.next = (next===undefined ? null : next)
 * }
 */
 
/**
 * @param {ListNode[]} lists
 * @return {ListNode}
 */
// Divide & Conquer approach : O(nklogk)
var mergeKLists = function(lists) {
	if (lists === null || lists.length === 0) {
		return null;
	}
	return mergeKListsHelper(lists, 0, lists.length - 1);
};

/**
 * @param {ListNode} n1
 * @param {ListNode} n2
 * @return {ListNode}
 */
// Merge two sorted linked lists
var mergeTwoLists = function(n1, n2) {
	if (n1 === null) {
		return n2;
	} else if (n2 === null) {
		return n1;
	} else if (n1.val < n2.val) {
		n1.next = mergeTwoLists(n1.next, n2);
		return n1;
	} else {
		n2.next = mergeTwoLists(n1, n2.next);
		return n2;
	}
};

/**
 * @param {ListNode[]} lists
 * @param {int} start 
 * @param {int} end
 * @return {ListNode}
 */
var mergeKListsHelper = function(lists, start, end) {
	if (start === end) {
		return lists[start];
	}
	const mid = start + Math.floor((end - start) / 2);
	const left = mergeKListsHelper(lists, start, mid);
	const right = mergeKListsHelper(lists, mid + 1, end);
	return mergeTwoLists(left, right);
};
