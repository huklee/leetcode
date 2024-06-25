public class Solution {
	public int maxSubArray(int[] nums) {
		if (nums.length == 0)
			return 0;
		
		int maxVal = nums[0];
		int DP = nums[0];
		
		for (int i = 1; i < nums.length; i++) {
			DP = Math.max(DP + nums[i], nums[i]);
			maxVal = Math.max(maxVal, DP);
		}
		
		return maxVal;
	}
}
