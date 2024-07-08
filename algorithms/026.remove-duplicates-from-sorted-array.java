class Solution {
	public int removeDuplicates(int[] nums) {
		int nonDupIndex = 0;
		int prev = -101;
		for (int i=0; i < nums.length; i++){
			if (prev != nums[i]){
				prev = nums[i];  
				nums[nonDupIndex] = nums[i];
				nonDupIndex++;
			}
		}
		return nonDupIndex;
	}
}
