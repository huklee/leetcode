# 003. Longest Substring wihtout repeating chars
# author: github.com/huklee
# TC O(n) solution using a single hash map
class Solution:
    def dedup(self, s, start, end, charSet) -> int:
        for j in range(end - start):
            if s[start] == s[end]:
                start += 1
                break
            else: 
                charSet.discard(s[start]) 
                start += 1
        return start

    def lengthOfLongestSubstring(self, s: str) -> int:
        start, end, maxSubStr = 0, 0, 0
        charSet = set()
        for i in range(len(s)):
            end = i
            if s[i] not in charSet:
                charSet.add(s[i])
                maxSubStr = max(maxSubStr, end - start + 1)
            else:
                start = self.dedup(s, start, end, charSet)
        return maxSubStr
