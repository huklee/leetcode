# 005. Longest Palindrom
# author: huklee
# disc: TC O(n^2) solution with growing centers

class Solution:
    def checkPal(self, pivot, s, maxLen, maxPal) -> (int, str):
        # odd case
        for j in range(len(s)):
            # maxLen, maxPal = self.checkPal(start, end, maxLen)
            if pivot - j < 0 or pivot + j >= len(s):
                break
            if s[pivot - j] != s[pivot + j]:
                break
            if 2*j + 1 > maxLen:
                maxLen = 1 + 2*j
                maxPal = s[pivot - j:pivot + j + 1]

        if pivot == len(s) - 1:
            return maxLen, maxPal
        # even case
        for j in range(len(s)):
            if pivot - j + 1 < 0 or pivot + j >= len(s):
                break
            elif s[pivot - j + 1] != s[pivot + j]:
                break
            elif 2*j > maxLen:
                maxLen = 2*j
                maxPal = s[pivot - j + 1:pivot + j + 1]
                
        return maxLen, maxPal

    def longestPalindrome(self, s: str) -> str:
        maxLen = 0
        maxPal = ""
        for i in range(len(s)):
            maxLen, maxPal = self.checkPal(i, s, maxLen, maxPal)
        return maxPal
