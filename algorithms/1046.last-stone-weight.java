class Solution {
	// Orderd insertion solution
	// TC: 1 sort + 1 list creation + n*insertions
	// = O(NlogN) + O(N) + O(N^2) = O(N^2)
	public int lastStoneWeightUsingInsertion(int[] stones) {
		// Sort the stones array in descending order
		Arrays.sort(stones);
		LinkedList<Integer> llist = new LinkedList<>();
		for (int i = 0; i < stones.length; i++) {
			llist.addLast(stones[i]);
		}

		while (llist.size() > 1) {
			int first = llist.removeLast();
			int second = llist.removeLast();
			if (first != second) {
				insertInOrder(llist, first - second);
			}
		}

		return llist.isEmpty() ? 0 : llist.getFirst();
	}

	private void insertInOrder(LinkedList<Integer> llist, int stone) {
		int i = 0;
		while (i < llist.size() && llist.get(i) < stone) {
			i++;
		}
		llist.add(i, stone);
	}

	// Solution using Priority Queue
	// TC: new PQ + n*insertionInOrder
	// = O(NlogN) + O(NlogN) = O(NlogN)
	public int lastStoneWeight(int[] stones) {
		PriorityQueue<Integer> pq = new PriorityQueue<>((a, b) -> b - a); // Max heap

		for (int stone : stones) {
			pq.offer(stone);
		}

		while (pq.size() > 1) {
			int first = pq.poll();
			int second = pq.poll();
			if (first > second) {
				pq.offer(first - second);
			}
		}

		return pq.isEmpty() ? 0 : pq.peek();
	}
}
