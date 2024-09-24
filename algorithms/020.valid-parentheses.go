func isValid(s string) bool {
    stack := []rune{}
    match := map[rune]rune{')': '(', '}' : '{', ']' : '['}

    for _, char := range s {
        // char is a closing bracket
        if open, found := match[char]; found {
            // check for matching opening bracket
            if len(stack) == 0 || stack[len(stack) - 1] != open {
                return false
            }
            // Pop the stack
            stack = stack[:len(stack) - 1]
        } else {
            // Push opening bracket
            stack = append(stack, char)
        }
    }

    // Return true if no unmatched brackets
    return len(stack) == 0
}
