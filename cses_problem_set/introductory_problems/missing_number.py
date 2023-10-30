n = int(input().strip())

t = [0] * (n + 1)

a = input().split(" ")
for i in a:
    t[int(i)] = 1

for i in range(1, len(t) + 1):
    if t[i] == 0:
        print(i)
        break
