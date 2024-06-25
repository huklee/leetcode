class Solution {
  // O(n^2) solution for finding the middle of palindromes
	public String longestPalindrome(String s) {
		if (s == null || s.isEmpty()) return "";

		int n = s.length();
		int maxLen = 1;
		String maxStr = s.substring(0, 1);

		for (int mid = 0; mid < n; mid++) {
			// 1. Max odd-length palindrome centered at mid
			for (int j = 0; mid - j >= 0 && mid + j < n; j++) {
				if (s.charAt(mid - j) != s.charAt(mid + j)) break;
				int len = 2 * j + 1;
				if (len > maxLen) {
					maxLen = len;
					maxStr = s.substring(mid - j, mid + j + 1);
				}
			}

			// 2. Max even-length palindrome centered at mid and mid+1
			for (int j = 0; mid - j >= 0 && mid + 1 + j < n; j++) {
				if (s.charAt(mid - j) != s.charAt(mid + 1 + j)) break;
				int len = 2 * j + 2;
				if (len > maxLen) {
					maxLen = len;
					maxStr = s.substring(mid - j, mid + 1 + j + 1);
				}
			}
		}
		return maxStr;
	}
}
