class Solution {
	public int myAtoi(String s) {
		// Trim leading and trailing whitespace
		s = s.trim();
		
		// Check if string is empty after trimming
		if (s.isEmpty()) {
			return 0;
		}
		
		// Check for sign (+ or -)
		char sign = '+';
		int index = 0;
		if (s.charAt(0) == '+' || s.charAt(0) == '-') {
			sign = s.charAt(0);
			index++;
		}
		
		// Convert string to number
		long result = 0;
		while (index < s.length() && Character.isDigit(s.charAt(index))) {
			result = result * 10 + (s.charAt(index) - '0');
			
			// Check for overflow
			if (sign == '+' && result > Integer.MAX_VALUE) {
				return Integer.MAX_VALUE;
			} else if (sign == '-' && -result < Integer.MIN_VALUE) {
				return Integer.MIN_VALUE;
			}
			
			index++;
		}
		
		// Apply sign
		return sign == '-' ? (int) -result : (int) result;
	}
}
