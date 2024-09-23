func twoSum(nums []int, target int) []int {
    hashMap := make(map[int]int)
    for i, num := range nums{
        hashMap[num] = i
    }

    for i, num := range nums {
        complement := target - num
        if j, ok := hashMap[complement]; ok && i != j {
            return []int{i, j}
        }
    }
    return nil
}
