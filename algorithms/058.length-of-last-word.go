type Solution struct{}

// Split function to split a string by a delimiter and return a slice of strings
func (sol *Solution) split(s string, delim rune) []string {
	return strings.Split(s, string(delim))
}

// Trim function to remove leading and trailing occurrences of a specific character from the string
func (sol *Solution) trim(s string, c rune) string {
	start, end := 0, len(s)-1

	// Trim leading characters
	for start < len(s) && rune(s[start]) == c {
		start++
	}

	// Trim trailing characters
	for end >= start && rune(s[end]) == c {
		end--
	}

	return s[start : end+1]
}

// Function to find the length of the last word in a string
func (sol *Solution) lengthOfLastWord(s string) int {
	trimmed := sol.trim(s, ' ')
	words := sol.split(trimmed, ' ')
	if len(words) > 0 {
		return len(words[len(words)-1])
	}
	return 0
}
