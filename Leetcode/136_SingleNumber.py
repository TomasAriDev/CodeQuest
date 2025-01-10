class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        res = {}
        for num in nums:
            if num not in res:
                res[num] = 1
            else:
                del res[num]
        key, val = res.popitem()
        return key