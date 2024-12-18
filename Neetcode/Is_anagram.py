class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        # Analizamos sizes
        if len(s) != len(t):
            return False

        # Ahora analizamos los caracteres
        s_dicc = {}
        t_dicc = {}

        # Recorremos ambos stings s y t, agregamos en sus dicc
        for char in s:
            if char not in s_dicc:
                s_dicc[char] = 1
            else:
                s_dicc[char] += 1


        for char in t:
            if char not in t_dicc:
                t_dicc[char] = 1
            else:
                t_dicc[char] += 1

        # Condiciones de rechazo
        for key, value in s_dicc.items():
            if key not in t_dicc or t_dicc[key] != value:
                return False

        return True
        