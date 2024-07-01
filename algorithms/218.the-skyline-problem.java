// Height sorting and counting the only height change solution using PriorityQueue
// TC: O(nlogn)

class Point {
	int x;
	int h;
	boolean isStart;
	Point (int x, int h, boolean isStart){
		this.x = x;
		this.h = h;
		this.isStart = isStart;
	}
}

class Solution {
	public List<List<Integer>> getSkyline(int[][] buildings) {
		List<List<Integer>> result = new ArrayList<>();
		List<Point> points = new ArrayList<>();
		for (int i =0 ;i < buildings.length; i++){
			int left = buildings[i][0];
			int right = buildings[i][1];
			int height = buildings[i][2];
			points.add(new Point(left, height, true));
			points.add(new Point(right, height, false));
		}
		
		Collections.sort(points, (a, b) -> {
			if (a.x != b.x)
				return a.x - b.x;   // Smaller x comes first
			else if (a.isStart != b.isStart)
				return (b.isStart ? 1 : 0) - (a.isStart ? 1 : 0);   // Start comes fist
			else if (a.isStart == b.isStart && a.isStart == true)
				return b.h - a.h;   // for Start, larger height comes fist
			else
				return a.h - b.h;   // for End, smaller height comes fist
		});

		// Setting for Maxheap
		Queue<Integer> heights = new PriorityQueue<>((a, b) -> b - a);
		heights.offer(0);
		int prevHeight = 0;
		for (Point p: points){
			// Height add or remove from the PQ
			if (p.isStart){
				heights.offer(p.h);
			}
			else{
				heights.remove(p.h);
			}

			int currentMaxHeight = heights.peek();
			// if height changes, record the changed point
			if (prevHeight != currentMaxHeight){
				result.add(new ArrayList<>(List.of(p.x, currentMaxHeight)));
				prevHeight = currentMaxHeight;
			}
		}
		return result;
	}

}
