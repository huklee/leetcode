class Solution(object):
    def isScramble(self, s1, s2):
        """
        :type s1: str
        :type s2: str
        :rtype: bool
        """
        # 01. base case
        assert (len(s1) == len(s2) and len(s1) > 0)
        if len(s1) == 1 and s1[0] == s2[0]:
            return True

        # 02. recursive case
        dictS1, dictS2, dictInvS1 = {}, {}, {}
        for i in range(len(s1) - 1):
            dictS1[s1[i]] = dictS1.get(s1[i], 0) + 1
            dictS2[s2[i]] = dictS2.get(s2[i], 0) + 1
            dictInvS1[s1[len(s1) - 1 - i]] = dictInvS1.get(s1[len(s1) - 1 - i], 0) + 1
            # case not reversed
            if dictS1 == dictS2:
                solA = self.isScramble(s1[:i + 1], s2[:i + 1])
                solB = self.isScramble(s1[i + 1:], s2[i + 1:])
                if solA and solB:
                    return True
            # case reversed
            if dictInvS1 == dictS2:
                solA = self.isScramble(s1[len(s1) - i - 1:], s2[:i + 1])
                solB = self.isScramble(s1[:len(s1) - i - 1], s2[i + 1:])
                if solA and solB:
                    return True
        return False

