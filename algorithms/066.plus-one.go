func reverse(digits []int){
    for i, j := 0, len(digits) - 1; i < j; i, j = i + 1, j - 1 {
        digits[i], digits[j] = digits[j], digits[i]
    }
}

func plusOne(digits []int) []int {
    reverse(digits)
    carry := 1
    for i := 0; i < len(digits) && carry > 0; i++ {
        digits[i], carry = (digits[i] + carry)%10, (digits[i] + carry)/10
    }
    if carry == 1 {
        digits = append(digits, 1)
    }

    reverse(digits)
    return digits
}
