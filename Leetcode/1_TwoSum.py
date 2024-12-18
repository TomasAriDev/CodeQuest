from typing import List  

class Solution:
    # con hash -> revisamos n
    # la idea es ir revisando numero a numero,
    # si encontramos a su 'faltante' estamos listos
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        pair = {}

        for i, num in enumerate(nums):
            # preguntamos si existe la resta del numero pos i
            # con target, entonces existe resultado para el arreglo a regresar 
            if target - num in pair:
                return [i , pair[target-num]]
            # luego simplemente agregamos si es que no esta
            pair[num] = i
    
"""
Como comentario en la primera existe la indicación de:
- Only one valid answer exists.
- Además da igual el orden en el que salen ambos indicadores
"""

class Solution2:
    # fuerza bruta -> revisamos n^2
    # revisamos todo el arreglo por la suma
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        for i in range(len(nums)):
            for j in range(i+1, len(nums)):
                if nums[j] + nums[i] == target:
                    return [i,j]
        return []

solution = Solution()
print("Solution 1 (hashing):", solution.twoSum([2, 7, 11, 15], 9))  # Debería devolver [1, 0]

solution2 = Solution2()
print("Solution 2 (brute force):", solution2.twoSum([2, 7, 11, 15], 9))  # Debería devolver [0, 1]
