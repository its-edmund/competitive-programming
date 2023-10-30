n = int(input().strip())

for k in range(1, n + 1):
    area = k * k
    total = area * (area - 1) // 2
    if k > 2:
        total -= 4 * (k - 1) * (k - 2)
    print(total)
            
