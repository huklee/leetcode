func climbStairs(n int) int {
    // Base case: If there are 1 or 2 stairs, return n directly
    if n <= 2 {
        return n
    }

    // Create a memoization array to store the number of ways to climb stairs
    memo := make([]int, n+1)
    memo[1] = 1 // 1 way to climb 1 stair
    memo[2] = 2 // 2 ways to climb 2 stairs

    // Calculate the number of ways to climb each subsequent stair
    for i := 3; i <= n; i++ {
        memo[i] = memo[i-1] + memo[i-2] // The number of ways to reach step i
    }

    // Return the total number of ways to reach the nth step
    return memo[n]
}

