// Segment overlapping solution : Very complex
// TC: O(n^2)

class LineSegment{
	int l;
	int r;
	int h;
	LineSegment(int l, int r, int h){
		this.l = l;
		this.r = r;
		this.h = h;
	}
}

class Solution {
	boolean isDebug = false;
	public List<List<Integer>> getSkyline(int[][] buildings) {
		// 1. Divide and collect all line segments 
		ArrayList<LineSegment> segments = new ArrayList<>();
		
		for (int i = 0; i < buildings.length; i++) {
			assert buildings[i].length == 3;
			int leftX = buildings[i][0];
			int rightX = buildings[i][1];
			int heightY = buildings[i][2];

			if (isDebug)   System.out.printf("Considering building [%d,%d,%d]\n", leftX, rightX, heightY);

			for (int j = 0; j < buildings.length ; j++) {
				int leftXComp = buildings[j][0];
				int rightXComp = buildings[j][1];
				int heightYComp = buildings[j][2];
				if (j == i || leftXComp == rightXComp)
					continue;
				if (isDebug)   System.out.printf("[%d]: %d, %d, %d\n", j, leftXComp, rightXComp, heightYComp);

				// 1. everything is overlapped - skip this segment
				if (heightY <= heightYComp){
					if (leftXComp <= leftX && rightX <= rightXComp) {
						if (isDebug)   System.out.printf(
							"[%d,%d,%d] skip this part\n", leftX, rightX, heightY);
						leftX = rightX;
						if (heightY == heightYComp){
							if (isDebug)   System.out.println("Update left into " + rightX);
							buildings[i][0] = rightX;
						}
					}
					// 2. left part is overlapped - remove left part
					else if (leftXComp <= leftX && leftX <= rightXComp && rightXComp <= rightX) {
						if (isDebug)   System.out.printf(
							"[%d,%d,%d] no left\n", leftX, rightXComp, heightY);
						leftX = rightXComp;
						if (heightY == heightYComp){
							if (isDebug)   System.out.println("Update left into " + rightXComp);
							buildings[i][0] = rightXComp;
						}
					}
					// 4. right part is overlapped - remove right part
					else if (leftX <= leftXComp && leftXComp <= rightX && rightX <= rightXComp){
						if (isDebug)   System.out.printf(
							"[%d,%d,%d] no right\n", leftXComp, rightX, heightY);
						rightX = leftXComp;
						if (heightY == heightYComp){
							System.out.println("Update right into " + leftXComp);
							buildings[i][1] = leftXComp;
						}
					}
					// 3. middle part is overlapped - add left part & go with right part
					else if (leftX <= leftXComp && rightXComp <= rightX) {
						if (isDebug)   System.out.printf(
							"[%d,%d,%d] no middle\n", leftXComp, rightXComp, heightY);
						if (isDebug)   System.out.printf(
							"[%d,%d,%d] Add segment \n", leftX, leftXComp, heightY);
						segments.add(new LineSegment(leftX, leftXComp, heightY));
						leftX = rightXComp;
					}
				}
			}
			
			if (leftX < rightX){
				if (isDebug)   System.out.printf(
					"[%d,%d,%d] Add segment \n", leftX, rightX, heightY);
				segments.add(new LineSegment(leftX, rightX, heightY));
			}
		}

		segments.sort((a, b) -> a.l == b.l 
				? Integer.compare(a.h, b.h) 
				: Integer.compare(a.l, b.l));


		if (isDebug)   {
			// Only for debugging
			for (LineSegment p: segments){
				System.out.printf("(%d,%d,%d)\n", p.l, p.r, p.h);
			}
		}
		// 2. record left points of line segmets and end contour points
		LineSegment lastSegment = null;
		List<List<Integer>> result = new ArrayList<>();
		for (int i = 0; i < segments.size(); i++){
			LineSegment segment = segments.get(i);
			// 1. record end point if it jumps to another building
			if (lastSegment != null && lastSegment.r < segment.l){
				result.add(new ArrayList<>(List.of(lastSegment.r, 0)));
			}
			
			// 2. record left for each segment unless it continues from the last point
			if (lastSegment == null 
					|| lastSegment.h != segment.h || lastSegment.r < segment.l)
				result.add(new ArrayList<>(List.of(segment.l, segment.h)));

			lastSegment = segment;
		}
		// for the end of contour
		if (lastSegment != null)
			result.add(new ArrayList<>(List.of(lastSegment.r, 0)));

		if (isDebug)   {
			System.out.print("[");
			for (List<Integer> l: result){
				System.out.print("[");
				System.out.print(l.get(0) + "," + l.get(1));
				System.out.print("],");
			}
			System.out.println("]");

			if (Arrays.stream(buildings).allMatch(x -> Arrays.stream(x).allMatch(y -> y < 30))) {
				debugPrintBuildings(buildings);
			}
		}

		return result;
	}

	public static void debugPrintBuildings(int[][] buildings) {
		// Find the maximum x-coordinate to determine the width of the map
		int maxX = 0;
		for (int[] building : buildings) {
			maxX = Math.max(maxX, building[1]);
		}

		// Create an array to represent the skyline
		int[] skyline = new int[maxX + 1];
		for (int[] building : buildings) {
			int leftX = building[0];
			int rightX = building[1];
			int height = building[2];
			for (int x = leftX; x < rightX; x++) {
				skyline[x] = Math.max(skyline[x], height);
			}
		}

		// Print the skyline map
		System.out.println("============ Print the 2D Map ============");
		for (int y = Arrays.stream(skyline).max().getAsInt(); y >= 0; y--) {
			for (int x = 0; x <= maxX; x++) {
				if (skyline[x] >= y) {
					System.out.print("X");
				} else {
					System.out.print(" ");
				}
			}
			System.out.println();
		}
	}

}
