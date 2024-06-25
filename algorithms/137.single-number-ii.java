public class Solution {
	// O(n) * 32 solution with bitwise solutions
	// Iterate through each bit position (from 0 to 31 for 32-bit integers)
	public int singleNumber(int[] nums) {
		int ans = 0;
		for (int i = 0; i < 32; ++i) {
			int sum = 0;
			for (final int num : nums)
				sum += (num >> i) & 1;  // get the i-th bit
			sum %= 3;           // filter out 3-occurence numbers
			ans |= sum << i;    // Set the i-th bit of the single number
		}

		// Return the final result number which is the single number
		return ans;
	}

	// O(NlogN) solution with sorting solution
	public int singleNumberWithSort(int[] nums) {
		Arrays.sort(nums);

		for(int i=0;i<nums.length-1;i+=3){
			if(nums[i]!=nums[i+1]){
				return nums[i];
			}
			
		}
		 return nums[nums.length-1];
	}
}
