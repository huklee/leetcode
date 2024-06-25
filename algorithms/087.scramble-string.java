class Solution {
	// 3D memoization of traversal paths
	Boolean[][][] memoization;
	char[] str1, str2;
	int length;

	public boolean isScramble(String s1, String s2) {
		this.str1 = s1.toCharArray();
		this.str2 = s2.toCharArray();
		this.length = s1.length();
		this.memoization = new Boolean[length][length][length + 1];
		return canScramble(0, 0, length);
	}

	// Recursive function to check if substrings of length 'len' 
	// starting at 'i' in str1 and 'j' in str2 are scramble strings
	private boolean canScramble(int i, int j, int len) {
		if (len == 1)
			return memoization[i][j][len] = (str1[i] == str2[j]);

		if (memoization[i][j][len] != null)
			return memoization[i][j][len];
		
		for (int k = 1; k < len; k++) {
			// Without swapping
			if (canScramble(i, j, k) && canScramble(i + k, j + k, len - k))
				return memoization[i][j][len] = true;
			
			// With swapping
			else if (canScramble(i, j + len - k, k) && canScramble(i + k, j, len - k))
				return memoization[i][j][len] = true;
		}

		// If all possibilities failed, return false
		return memoization[i][j][len] = false;
	}
}
