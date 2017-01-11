from collections import OrderedDict

class Solution(object):
    def romanToInt(self, s):
        """
        :type s: str
        :rtype: int
        """
        result = 0
        temp = s
        roman_dict = OrderedDict()
        roman_dict["CM"] = 900
        roman_dict["M"] = 1000
        roman_dict["CD"] = 400
        roman_dict["D"] = 500
        roman_dict["XC"] = 90
        roman_dict["C"] = 100
        roman_dict["XL"] = 40
        roman_dict["L"] = 50
        roman_dict["IX"] = 9
        roman_dict["X"] = 10
        roman_dict["IV"] = 4
        roman_dict["V"] = 5
        roman_dict["I"] = 1
        for oneDict in roman_dict:
            if oneDict not in temp:
                continue
            while oneDict in temp:
                result += roman_dict[oneDict]
                pos = temp.find(oneDict)
                if len(oneDict) == 2:
                    temp = temp[:pos] + "__" + temp[pos + 2:]
                else:
                    temp = temp[:pos] + "_" + temp[pos + 1:]            
        return result
