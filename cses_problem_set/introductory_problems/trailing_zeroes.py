import math

n = int(input())

ans = 0
count = 1
while 5 ** count <= n:
    ans += n // (5 ** count)
    count += 1
print(ans)
