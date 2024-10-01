type Solution struct {
	memoization [][][]*bool
	str1, str2  []rune
	length      int
}

func (sol *Solution) isScramble(s1 string, s2 string) bool {
	sol.str1 = []rune(s1)
	sol.str2 = []rune(s2)
	sol.length = len(s1)
	sol.memoization = make([][][]*bool, sol.length)
	for i := range sol.memoization {
		sol.memoization[i] = make([][]*bool, sol.length)
		for j := range sol.memoization[i] {
			sol.memoization[i][j] = make([]*bool, sol.length+1)
		}
	}
	return sol.canScramble(0, 0, sol.length)
}

func (sol *Solution) canScramble(i, j, length int) bool {
	// Base case: strings of length 1
	if length == 1 {
		sol.memoization[i][j][length] = new(bool)
		*sol.memoization[i][j][length] = sol.str1[i] == sol.str2[j]
		return *sol.memoization[i][j][length]
	}

	// If result is already computed
	if sol.memoization[i][j][length] != nil {
		return *sol.memoization[i][j][length]
	}

	// Try splitting the strings in every possible way
	for k := 1; k < length; k++ {
		// Case 1: No swap
		if sol.canScramble(i, j, k) && sol.canScramble(i+k, j+k, length-k) {
			sol.memoization[i][j][length] = new(bool)
			*sol.memoization[i][j][length] = true
			return true
		}

		// Case 2: With swap
		if sol.canScramble(i, j+length-k, k) && sol.canScramble(i+k, j, length-k) {
			sol.memoization[i][j][length] = new(bool)
			*sol.memoization[i][j][length] = true
			return true
		}
	}

	// If no valid split was found
	sol.memoization[i][j][length] = new(bool)
	*sol.memoization[i][j][length] = false
	return false
}

