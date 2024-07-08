// O(n) solution using one hashSet
public class Solution {
	public int longestConsecutive(int[] nums) {
		if (nums.length == 0) return 0;

		Set<Integer> numSet = new HashSet<>();
		for (int num : nums) {
			numSet.add(num);
		}

		int longestStreak = 0;
		int longestStreakNum = 0;

		for (int num : numSet) {
			// Only check for the beginning of a sequence
			if (numSet.contains(num - 1))
				continue;
			
			int currentStreak = 1;

			while (numSet.contains(num + currentStreak))
				currentStreak++;

			if (longestStreak < currentStreak){
				longestStreak = currentStreak;
				longestStreakNum = num;
			}
		}

		// int[] result = IntStream.range(0, longestStreak).map(x -> x + longestStreakNum).toArray();
		return longestStreak;
	}
}
