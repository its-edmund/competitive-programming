x = input()
n = input().split(" ")

curr = int(n[0])
ans = 0

for i in range(1, len(n)):
    if curr > int(n[i]):
        ans += curr - int(n[i])
        curr = curr
    else:
        curr = int(n[i])
print(ans)
