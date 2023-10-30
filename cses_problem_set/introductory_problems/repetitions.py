s = input()

curr = ""
count = 0
ans = 1
for i in s:
    if curr != i:
        count = 1
        curr = i
    else:
        count += 1
        ans = max(ans, count)
print(ans)
