class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        result = []
        self.sub(result, "", n, n)
        return result
    
    def sub(self, result: List[str], current: str, cntOpen: int, cntClose: int):
        # Base case: if both counts reach zero, add the current combination to results
        if cntOpen == 0 and cntClose == 0:
            result.append(current)
            return
        
        # Add an open parenthesis if we can
        if cntOpen > 0:
            self.sub(result, current + "(", cntOpen - 1, cntClose)
        
        # Add a close parenthesis if it doesn't exceed the number of open parentheses
        if cntClose > cntOpen:
            self.sub(result, current + ")", cntOpen, cntClose - 1)