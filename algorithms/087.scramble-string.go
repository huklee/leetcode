var memo [][][]*bool
var str1, str2 string

func isScramble(s1 string, s2 string) bool {
    str1, str2 = s1, s2
	length := len(s1)
	memo = make([][][]*bool, length)
	for i := range memo {
		memo[i] = make([][]*bool, length)
		for j := range memo[i] {
			memo[i][j] = make([]*bool, length+1)
		}
	}
	return canScramble(0, 0, length)
}

func canScramble(i, j, length int) bool {
	// Base case: strings of length 1
	if length == 1 {
		memo[i][j][length] = new(bool)
		*memo[i][j][length] = str1[i] == str2[j]
		return *memo[i][j][length]
	}

	// If result is already computed
	if memo[i][j][length] != nil {
		return *memo[i][j][length]
	}

	// Try splitting the strings in every possible way
	for k := 1; k < length; k++ {
		// Case 1: No swap
		if canScramble(i, j, k) && canScramble(i+k, j+k, length-k) {
			memo[i][j][length] = new(bool)
			*memo[i][j][length] = true
			return true
		}

		// Case 2: With swap
		if canScramble(i, j+length-k, k) && canScramble(i+k, j, length-k) {
			memo[i][j][length] = new(bool)
			*memo[i][j][length] = true
			return true
		}
	}

	// If no valid split was found
	memo[i][j][length] = new(bool)
	*memo[i][j][length] = false
	return false
}

