var memoization [][][]*bool
var str1, str2 []rune

func isScramble(s1 string, s2 string) bool {
	str1 = []rune(s1)
	str2 = []rune(s2)
	length := len(s1)
	memoization = make([][][]*bool, length)
	for i := range memoization {
		memoization[i] = make([][]*bool, length)
		for j := range memoization[i] {
			memoization[i][j] = make([]*bool, length+1)
		}
	}
	return canScramble(0, 0, length)
}

func canScramble(i, j, length int) bool {
	// Base case: strings of length 1
	if length == 1 {
		memoization[i][j][length] = new(bool)
		*memoization[i][j][length] = str1[i] == str2[j]
		return *memoization[i][j][length]
	}

	// If result is already computed
	if memoization[i][j][length] != nil {
		return *memoization[i][j][length]
	}

	// Try splitting the strings in every possible way
	for k := 1; k < length; k++ {
		// Case 1: No swap
		if canScramble(i, j, k) && canScramble(i+k, j+k, length-k) {
			memoization[i][j][length] = new(bool)
			*memoization[i][j][length] = true
			return true
		}

		// Case 2: With swap
		if canScramble(i, j+length-k, k) && canScramble(i+k, j, length-k) {
			memoization[i][j][length] = new(bool)
			*memoization[i][j][length] = true
			return true
		}
	}

	// If no valid split was found
	memoization[i][j][length] = new(bool)
	*memoization[i][j][length] = false
	return false
}

