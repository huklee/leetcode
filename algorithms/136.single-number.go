// singleNumber 함수는 slice에서 단 하나만 존재하는 숫자를 찾습니다.
func singleNumber(nums []int) int {
    res := 0
    for _, num := range nums {
        res ^= num // XOR 연산으로 같은 숫자를 제거
    }
    return res
}
