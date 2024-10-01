func trim(s string, c rune) string {
    start, end := 0, len(s) - 1
    
    // Trim leading characters
    for start < len(s) && rune(s[start]) == c {
        start++
    }

    // Trim trailing characters
    for end >= start  && rune(s[end]) == c {
        end--
    }

    return s[start : end+1]
}

func lengthOfLastWord(s string) int {
    trimmed := trim(s, ' ')
    words := strings.Split(trimmed ," ")
    if len(words) > 0 {
        return len(words[len(words) - 1])    
    }
    return 0
}
