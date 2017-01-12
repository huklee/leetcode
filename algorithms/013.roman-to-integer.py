class Solution(object):
    def romanToInt(self, s):
        """
        :type s: str
        :rtype: int
        """
        roman_dict = {"C":100, "M":1000, "D":500, "C":100, "L":50, "X":10, "V":5, "I":1}
        result = 0
        for i in range(0, len(s) - 1):
            prev_char = s[i]
            next_char = s[i+1]
            # 01. next char is bigger than previous one, this is the minus operation
            if (roman_dict[prev_char] < roman_dict[next_char]):
                result -= roman_dict[prev_char]
            # 02. otherwise, it's addition
            else:
                result += roman_dict[prev_char]
        # for the last char, just plus
        result += roman_dict[s[len(s)-1]]
        return result
