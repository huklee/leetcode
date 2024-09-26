// singleNumber function finds the single number in the slice.
func singleNumber(nums []int) int {
    res := 0
    for _, num := range nums {
        res ^= num // Use XOR operation to eliminate the numbers that appear twice
    }
    return res
}
