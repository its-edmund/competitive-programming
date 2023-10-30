n = int(input().strip())

"""
6
1, 3, 5, 2, 4, 6

5
1, 3, 5, 2, 4
2, 4, 1, 3, 5,

4
2, 4, 1, 3
"""

ans = ""

if n == 2 or n == 3:
    print("NO SOLUTION")
else:
    odd = 1
    even = 2
    while even <= n:
        ans += f'{even} '
        even += 2
    while odd <= n:
        ans += f'{odd} '
        odd += 2
    print(ans)

