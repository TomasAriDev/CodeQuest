class Solution:
    def isPalindrome(self, x: int) -> bool:
        y = str(x)
        z = str(x)[::-1]
        if y == z:
            return True
        return False
    
