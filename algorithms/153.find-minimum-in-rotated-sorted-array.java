class Solution {
	// Binary serach solution with O(logN) space
	private int getMinBSWithRecursion(int[] arr, int s, int e){
		// Base case
		if (s == e)
			return arr[s];

		// Recursive case
		if (arr[s] < arr[e]){	// well ordered
			return arr[s];
		}
		else{
			int mid = (s + e)/2;
			return Math.min(getMinBSWithRecursion(arr, s, mid), getMinBSWithRecursion(arr, mid + 1, e));
		}   
	}

	// Binary serach with O(1) space
	private int getMinBSWithIteration(int[] nums){
		int s = 0, e = nums.length - 1;
		while (nums[s] > nums[e]){
			int mid = (s + e)/2;
			if (nums[s] > nums[mid])
				e = mid;
			else
				s = mid + 1;
		}
		return nums[s];
	}
	
	public int findMin(int[] nums) {
		// Edge case
		if (nums.length == 0)
			return 0;

		// return getMinBSWithRecursion(nums, 0, length - 1);
		return getMinBSWithIteration(nums);
	}
}
