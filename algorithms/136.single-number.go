func singleNumber(nums []int) int {
    singleNumber := 0
    for _, i := range nums {
        singleNumber ^= i
    } 
    return singleNumber
}
