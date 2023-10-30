n = int(input())
"""
7
7 4 3
6 5 2 1

8
8 5 4 1
7 6 3 2

"""

total = round(n / 2 * (1 + n))
if total % 2 == 0:
    l1 = ""
    l1_count = 0
    l1_sum = 0
    l2 = ""
    l2_count = 0
    l2_sum = 0
    for i in range(n, 0, -1):
        if l1_sum < l2_sum:
            l1 += f"{i} "
            l1_count += 1
            l1_sum += i
        else:
            l2 += f"{i} "
            l2_count += 1
            l2_sum += i
    print("YES")
    print(l1_count)
    print(l1)
    print(l2_count)
    print(l2)

else:
    print("NO")
