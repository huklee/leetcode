func removeElement(nums []int, val int) int {
    j := 0 

    // Loop through the array.
    for i := 0; i < len(nums); i++ {
        if nums[i] != val {
            nums[j], nums[i] = nums[i], nums[j] // Swap to place non-val at `j`.
            j++ 
        }
    }

    return j 
}

