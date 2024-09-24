func romanToInt(s string) int {
    romanDict := map[byte]int{
        'M': 1000,
        'D': 500,
        'C': 100,
        'L': 50,
        'X': 10,
        'V': 5,
        'I': 1,
    }

    result := 0
    n := len(s)

    for i := 0; i < n - 1; i++ {
        prevChar := s[i]
        nextChar := s[i + 1]

        if romanDict[prevChar] < romanDict[nextChar] {
            result -= romanDict[prevChar]
        } else {
            result += romanDict[prevChar]
        }
    }

    // Add the last character's value
    result += romanDict[s[n - 1]]

    return result
}
