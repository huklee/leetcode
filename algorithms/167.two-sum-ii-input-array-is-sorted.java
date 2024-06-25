public class Solution {
	public int[] twoSum(int[] numbers, int target) {
		int S = 0, E = numbers.length - 1;
		while (S < E) {
			while (target - numbers[S] < numbers[E]) {
				E--;
			}
			if (target - numbers[S] == numbers[E]) {
				return new int[]{S + 1, E + 1};
			} else {
				S++;
			}
		}
		return new int[]{-1, -1};
	}
}
