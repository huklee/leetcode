// O(n^2) solution using 2 pointers & hash
class Solution {
	public List<List<Integer>> threeSum(int[] nums) {
		HashMap<Integer, Integer> hashMap = new HashMap<>();
		for (int i: nums)
			hashMap.put(i, hashMap.getOrDefault(i, 0) + 1);

		List<List<Integer>> result = new ArrayList<>();
		Arrays.sort(nums);
		for (int i =0; i < nums.length; i++){
			if (i > 0 && nums[i - 1] == nums[i])
				continue;
			for (int j =i + 1; j < nums.length; j++){
				int candidateK = 0 - nums[i] - nums[j];
				if (nums[j] > candidateK 
						|| (j > i + 1 && nums[j - 1] == nums[j]))
					continue;

				int countDuplicateK = 1 + (candidateK == nums[i] ? 1 : 0) + (candidateK == nums[j] ? 1 : 0);
				if (hashMap.getOrDefault(candidateK, 0) >= countDuplicateK)
					result.add(Arrays.asList(nums[i], nums[j], candidateK));
			}
		} 
		return result;
	}
}
