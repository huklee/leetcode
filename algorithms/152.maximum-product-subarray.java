public class Solution {
	public int maxProduct(int[] nums) {
		// Edge case
		if (nums == null || nums.length == 0) {
			return 0;
		}
		
		double maxDP = nums[0];
		double minDP = nums[0];
		double maxGlobal = nums[0];
		
		// Iterate through the array starting from the second element
		for (int i = 1; i < nums.length; i++) {
			// Store the current maximum ending here before updating
			double tempMax = maxDP;
			
			// Update the maximum and minimum ending here
			double num = nums[i];
			maxDP = Math.max(Math.max(num, maxDP * num), minDP * num);
			minDP = Math.min(Math.min(num, tempMax * num), minDP * num);
			
			// Update the maximum product found so far
			maxGlobal = Math.max(maxGlobal, maxDP);
		}
		
		return (int) maxGlobal;
	}
}
