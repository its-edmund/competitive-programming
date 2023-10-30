from collections import Counter

s = input()

freq = Counter(s)

ans = ""
odd = False
fail = False

for c, f in freq.items():
    if f % 2 == 0:
        ans = ans + (c * (f // 2))
        ans = (c * (f // 2)) + ans
    else:
        if odd:
            print("NO SOLUTION")
            fail = True
            break
        else:
            odd = True
            ans = ans[:len(ans) // 2] + (c * f) + ans[len(ans) // 2:]
if not fail:
    print(ans)
