n = int(input())

ans = []
count = 0

def hanoi(n, start, end):
    global count
    count += 1
    if n == 1:
        ans.append((start, end))
        return 
    hanoi(n - 1, start, 6 - (start + end))
    ans.append((start, end))
    hanoi(n - 1, 6 - (start + end), end)

hanoi(n, 1, 3)
print(count)
for i in ans:
    print(i[0], i[1])
