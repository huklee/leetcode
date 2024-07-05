class Solution {
	public int firstMissingPositive(int[] nums) {
		// Let's assume that the ith element should represent value i 
		// (e.g. nums[0] = 1 , num[10] = 11 ...)
		// Place each number in its right place, value(=nums[i]) should be at nums[value - 1]
		int N = nums.length;
		for (int i = 0; i < N; i++) {
			int val = nums[i];
			while (val > 0 && val < N 
					&& val != i + 1			 // wrong position
					&& val != nums[val - 1]) {  // prevent infinite-looped swap 
				int temp = nums[val - 1];
				nums[val - 1] = val;
				nums[i] = temp;
				val = nums[i];
			}
		}

		// Find the first missing positive number
		for (int i = 0; i < N; i++) {
			if (nums[i] != i + 1) {
				return i + 1;
			}
		}

		// if All corrected array is well arranged, then N + 1
		return N + 1;
	}
}
