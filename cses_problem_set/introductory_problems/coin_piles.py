t = int(input())

for i in range(t):
    a, b = [int(n) for n in input().split(" ")]
    print("YES" if (a + b) % 3 == 0 and 2 * a >= b and 2 * b >= a else "NO")

