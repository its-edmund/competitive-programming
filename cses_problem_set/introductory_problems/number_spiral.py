t = int(input().strip())

for i in range(t):
    ans = 0
    y, x = [int(j) for j in input().split(" ")]
    ans = (max(y, x) - 1) ** 2
    if y < x:
        if x % 2 == 0:
            ans += y
            print(ans)
        else:
            ans += x
            ans += x - y
            print(ans)
    else:
        if y % 2 == 0:
            ans += y
            ans += y - x
            print(ans)
        else:
            ans += x
            print(ans)

