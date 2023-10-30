import math

q = int(input())

for i in range(q):
    k = int(input())


    curr = 0
    amount = 0
    prev = 0

    while curr < k:
        prev = curr
        curr += 9 * (10 ** amount) * (amount + 1)
        amount += 1

    k = k - prev
    number = round(k / amount) + (10 ** (amount - 1) - 1)
    print(str(number)[k % amount - 1])

