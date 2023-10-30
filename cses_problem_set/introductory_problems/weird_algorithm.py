n = int(input().strip())
while n != 1:
    print(n)
    if n % 2 == 1:
        n = n * 3 + 1
    elif n % 2 == 0:
        n //= 2
print(n)
