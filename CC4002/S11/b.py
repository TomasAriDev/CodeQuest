import io
import os
import sys
# yei python - en cpp era raro
def lps_calculo(pat):
    lps = [-1] * len(pat)
    concidence = -1
    for i in range(1, len(pat)):
        while concidence >= 0 and pat[i] != pat[concidence + 1]:
            concidence = lps[concidence]
        if pat[i] == pat[concidence + 1]:
            concidence += 1
        lps[i] = concidence
    return lps



s = input()
n = len(s)
lps = lps_calculo(s)
counter = [1] * (n + 1)
for i in range(n - 1, 0, -1):
    if lps[i] >= 0:
        counter[lps[i] + 1] += counter[i + 1]
ans = []
cur = n - 1
while cur != -1:
    ans.append((cur + 1, counter[cur + 1]))
    cur = lps[cur]
print(len(ans))
for l, c in ans[::-1]:
    print(l, c)




