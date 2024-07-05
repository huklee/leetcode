# 001. Two Sum
# author: github.com/huklee
# O(n) TC solution using a complement map
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        targetMap = {}
        for i in range(len(nums)):
            complement = target - nums[i]
            if complement in targetMap:
                j = targetMap[complement]
                return [min(i, j), max(i, j)] # Success
            else:
                targetMap[nums[i]] = i
        return [] # Fallback
