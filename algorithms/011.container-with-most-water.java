class Solution {
	public int maxArea(int[] height) {
		int left = 0;
		int right = height.length - 1;
		int maxProduct = 0; 

		// O(n) with Greedy algorithm
		// As of ground 1 & 2, move right point to the left to find higest product, local max.
		// With all left pivots, find global maximum.
		// Ground 1. Given a fixed left pivot, all other candidates 
		// lower than right point with heigher than left pivot can't be solutions. 
		// Ground 2. Given a right pivot which is greatest index with equal or heigher
		// than the left pivot, all other candidates on the left side can't be solutions.
		while (left < right){
			int lPivot = height[left];
			int rPivot = height[right];
			maxProduct = Math.max(maxProduct,
								  Math.min(lPivot, rPivot)*(right - left));
			while (height[right] < lPivot && left < right){
				right--;
				maxProduct = Math.max(maxProduct, (right - left)*Math.min(lPivot, height[right]));
			}
			left++;
		} 
		return maxProduct;
	}
}
