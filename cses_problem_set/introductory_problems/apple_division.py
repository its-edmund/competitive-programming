def main():
    n = int(input())
    p = [int(i) for i in input().split(" ")]
    p.sort(reverse=True)
    ans = float("inf")
    def bt(choices, curr1, curr2):
        nonlocal ans
        if len(choices) == 0:
            ans = min(ans, abs(curr1 - curr2))
            return
        else:
            choice = choices[0]
            bt(choices[1:], curr1 + choice, curr2)
            bt(choices[1:], curr1, curr2 + choice)
    bt(p, 0, 0)
    print(ans)

main()

