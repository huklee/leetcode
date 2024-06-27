import java.util.*;

class ListNode {
    int val;
    ListNode next;

    ListNode(int x) {
        val = x;
        next = null;
    }
}

public class Solution {
    // Merge two sorted linked lists
    public ListNode mergeTwoLists(ListNode n1, ListNode n2) {
        if (n1 == null) {
            return n2;
        } else if (n2 == null) {
            return n1;
        } else if (n1.val < n2.val) {
            n1.next = mergeTwoLists(n1.next, n2);
            return n1;
        } else {
            n2.next = mergeTwoLists(n1, n2.next);
            return n2;
        }
    }

    // Divide & Conquer approach : O(nklogk)
    public ListNode mergeKLists(List<ListNode> lists) {
        if (lists == null || lists.size() == 0) {
            return null;
        }
        return mergeKLists(lists, 0, lists.size() - 1);
    }

    private ListNode mergeKLists(List<ListNode> lists, int start, int end) {
        if (start == end) {
            return lists.get(start);
        }
        int mid = start + (end - start) / 2;
        ListNode left = mergeKLists(lists, start, mid);
        ListNode right = mergeKLists(lists, mid + 1, end);
        return mergeTwoLists(left, right);
    }

    // Brute-Force approach : O(nk^2)
    public ListNode mergeKListsBruteForce(List<ListNode> lists) {
        if (lists == null || lists.size() == 0) {
            return null;
        }

        ListNode head = null, prev = null;
        ListNode[] cur = {null};

        // Find the first non-null element
        for (ListNode node : lists) {
            if (node != null) {
                cur[0] = node;
                break;
            }
        }

        while ((cur[0] != null || prev != null)) {
            // Pick the minimum element
            for (ListNode node : lists) {
                if (node != null) {
                    if (cur[0] == null || cur[0].val > node.val) {
                        cur[0] = node;
                    }
                }
            }

            // Connect prev to cur
            if (prev != null) {
                prev.next = cur[0];
            }
            prev = cur[0];

            if (head == null) {
                head = cur[0];
            }

            if (cur[0] != null) {
                cur[0] = cur[0].next;
            }
        }

        return head;
    }

    // Helper method to convert a 2D array to a list of ListNode
    public List<ListNode> createListNodes(int[][] arrays) {
        List<ListNode> listNodes = new ArrayList<>();
        for (int[] array : arrays) {
            ListNode dummy = new ListNode(0);
            ListNode current = dummy;
            for (int value : array) {
                current.next = new ListNode(value);
                current = current.next;
            }
            listNodes.add(dummy.next);
        }
        return listNodes;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        // Test with some example lists
        int[][] input1 = {{1, 4, 5}, {1, 3, 4}, {2, 6}};
        List<ListNode> lists1 = solution.createListNodes(input1);
        ListNode mergedHead1 = solution.mergeKLists(lists1);
        printList(mergedHead1); // Output: 1 1 2 3 4 4 5 6

        int[][] input2 = {{2}, {}, {-1}};
        List<ListNode> lists2 = solution.createListNodes(input2);
        ListNode mergedHead2 = solution.mergeKLists(lists2);
        printList(mergedHead2); // Output: -1 2

        int[][] input3 = {{}, {}};
        List<ListNode> lists3 = solution.createListNodes(input3);
        ListNode mergedHead3 = solution.mergeKLists(lists3);
        printList(mergedHead3); // Output: (empty list)

        int[][] input4 = {{1}};
        List<ListNode> lists4 = solution.createListNodes(input4);
        ListNode mergedHead4 = solution.mergeKLists(lists4);
        printList(mergedHead4); // Output: 1

        int[][] input5 = {{}, {1}};
        List<ListNode> lists5 = solution.createListNodes(input5);
        ListNode mergedHead5 = solution.mergeKLists(lists5);
        printList(mergedHead5); // Output: 1
    }

    private static void printList(ListNode node) {
        while (node != null) {
            System.out.print(node.val + " ");
            node = node.next;
        }
        System.out.println();
    }
}
