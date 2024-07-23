class Solution {
	public int divide(int dividend, int divisor) {
		int offset = 0;
 
		// Edge cases
		if (dividend == Integer.MIN_VALUE){
			if (divisor == -1)
				return Integer.MAX_VALUE;
			if (divisor == Integer.MIN_VALUE)
				return 1;
			if (divisor == 1)
				return dividend;
			dividend += divisor > 0 ? divisor : -divisor;
			offset = 1;
		} 

		if (divisor == Integer.MIN_VALUE)
			return 0;

		// one case
		if (Math.abs(divisor) == 1 )
			return divisor > 0 ? dividend : -dividend;

		return divideUsingBitOperation(dividend, divisor, offset);	
	}
	
	// fast solution with bitoperation : max 31 + 30 + ... + 1 = 465 operations
	private int divideUsingBitOperation(int dividend, int divisor, int offset) {
		int result = offset;
		int threshold = 1 << 30; // used to avoid overflow
		boolean isNeg = (dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0);
		dividend = Math.abs(dividend);
		divisor = Math.abs(divisor);
		while (dividend >= divisor) {
			int bitCount = 1;
			int curDivisor = divisor;
			while (curDivisor < threshold && dividend >= (curDivisor << 1)) {
				curDivisor <<= 1;
				bitCount <<= 1;
			}
			dividend -= curDivisor;
			result += bitCount;
		}
		return isNeg ? -result : result;
	}

	// slow solution: max 2^31 operations
	private int divideUsingOnlySub(int dividend, int divisor, int offset){
		int result = offset;
		boolean isNeg = (dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0);
		dividend = Math.abs(dividend);
		divisor = Math.abs(divisor);
		assert divisor != 0;
		while (dividend >= divisor){
			dividend -= divisor;
			result++;
		}
		return isNeg ? -result: result;
	}

}
