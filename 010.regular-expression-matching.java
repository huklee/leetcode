class Solution {
	// TC: O(n*m), SC: 0(n*m) solution using DP
	public boolean isMatch(String s, String p) {
		int m = s.length();
		int n = p.length();
		
		// dp[i][j]: true if the 0 ~ ith elems of s matches 0 ~ jth elems of p
		// note that i should be (= 1 ... ith) = (s[0], ... , s[i-1])
		boolean[][] dp = new boolean[m + 1][n + 1];

		// only if both i & j reaches to the empty strings, it matches
		dp[0][0] = true;
		
		// Fill dp for patterns that can match an empty string
		// : Patterns like a*, a*b*, .* can match an empty string,
		// so we initialize dp[0][j] accordingly.
		for (int j = 2; j <= n; j++) {
			if (p.charAt(j - 1) == '*') {
				dp[0][j] = dp[0][j - 2];
			}
		}
		
		// Fill the dp table
		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= n; j++) {
				if (p.charAt(j - 1) == '.' || p.charAt(j - 1) == s.charAt(i - 1)) {
					dp[i][j] = dp[i - 1][j - 1];
				} else if (p.charAt(j - 1) == '*') {
					// Consider zero occurrence of the character before '*'
					dp[i][j] = dp[i][j - 2]; 

					if (p.charAt(j - 2) == '.' || p.charAt(j - 2) == s.charAt(i - 1)) {
						// Consider one or more occurrence of the character before '*'
						dp[i][j] = dp[i][j] || dp[i - 1][j]; 
					}
				}
			}
		}
		
		return dp[m][n];
	}


	// Inefficient Solution with O(n^m) solution depending on the number of * wildcard
	public boolean isMatchUsingRecursive(String s, String p) {
		boolean result = isMatchFixedIndex(s, p, 0);
		return result;
	}

	private boolean isMatchFixedIndex(String s, String p, int start) {
		// Edge case handling
		if (start == s.length()) {
			boolean result = p.length() == 0;
			return result;
		}

		int i = 0;
		for (i = 0; i < p.length(); i++) {
			// * character handling
			if (i < p.length() - 1 && p.charAt(i + 1) == '*') {
				char repChar = p.charAt(i);
				int j = 0;
				boolean isWildcardNoMatch = false;
				while (start + i + j <= s.length()) {
					// Recursive excluding [c]* case starting 0 occurence
					if (isMatchFixedIndex(s, p.substring(i + 2), start + i + j + 0)) {
						return true;
					}
					else if (start + i + j < s.length() 
								&& repChar != '.' 
								&& s.charAt(start + i + j) != repChar) {
						isWildcardNoMatch = true;
						break;
					}
					j++;
				}

				// if any of the wildcard doensn't match, it fails .
				if (isWildcardNoMatch){
					return false;   
				}
				else{
					// skip wildcard
					i++;
				}
			}
			// . character handling
			else if (start + i < s.length() && p.charAt(i) == '.') {
				continue;
			}
			// other character && edge case handling
			else if (start + i >= s.length() 
						|| s.charAt(start + i) != p.charAt(i)) {
				return false;
			}
		}

		// Default case is no unmatch is found
		// then start + i should reach to the end of String s.
		boolean result = (i + start >= s.length());
		return result;
	}
	 
	// Simple solution using base regex function
	public boolean isMatchUsingBaseMethod(String s, String p) {
		boolean result = s.matches(p);
		return result;
	}
}
