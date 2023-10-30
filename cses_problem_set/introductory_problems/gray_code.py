import sys

sys.setrecursionlimit(100000)
n = int(input())

def r(curr, n, visited):
    if len(curr) == 2 ** n:
        return True
    mask = 1
    while mask <= 2 ** n:
        newNum = curr[-1] ^ mask
        if newNum not in visited:
            visited.add(newNum)
            curr.append(newNum)
            if r(curr, n, visited):
                return True
            curr.pop()
            visited.remove(newNum)
        mask <<= 1
    return False

ans = [0]
visited = set({0})
r(ans, n, visited)
for i in ans:
    print(bin(i)[2:].zfill(n))

