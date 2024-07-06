/**
 * @param {number} n
 * @return {number}
 */
var memo = {};
var climbStairs = function(n) {
	if (n <= 2)
		return n;
	if (!memo.hasOwnProperty(n))
		memo[n] = climbStairs(n-1) + climbStairs(n-2);
	return memo[n]
};
