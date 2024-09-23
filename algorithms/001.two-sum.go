func twoSum(nums []int, target int) []int {
    hashMap := make(map[int]int)
    for i, num := range nums{
        hashMap[num] = i
    }

    for i := 0; i < len(nums); i++{
        complement := target - nums[i]
        if j, ok := hashMap[complement]; ok && i != j {
            return []int{i, j}
        }
    }
    return nil
}
