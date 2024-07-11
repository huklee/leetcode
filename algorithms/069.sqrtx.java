class Solution {
	// Simple solution using Math.sqrt() & Math.floor()
	public int mySqrt(int x){
		return (int) Math.floor(Math.sqrt(x));
	}

	public int mySqrtUsingBS(int x) {
		// Edge cases
		if (x == 0 || x == 1)
			return x;

		// Binary search approach
		int left = 0, right = x;
		while (left <= right){
			int mid = (right + left)/2;
			
			// using division can avoid overflow
			if (mid == x/mid)
				return mid;
			else if (mid < x/mid)
				left = mid + 1;
			else 
				right = mid - 1;
		}
		return right;
	}
}
