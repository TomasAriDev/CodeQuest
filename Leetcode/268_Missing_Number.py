class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        n = len(nums)
        nums_ = set(nums)
        i = 0
        while i<n:
            if {i}.issubset(nums_):
                i+=1
            else:
                break
        return i
    
# Usando el metodo de set 'issubset' es posible preguntar si
# i esta en nums_, si no lo esta es muy facil saber cual es el que falta

# ajustamos conflicto de git