from typing import List  

class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        s = {}
        for i, num in enumerate(nums):
            if num in s:
                return True
            s[num] = i 
        return False

# Muy parecido a como resolver el two sums eficientemente en Leetcode