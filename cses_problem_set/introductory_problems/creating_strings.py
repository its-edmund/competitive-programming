
def main():
    s = input()
    added = set()
    count = 0
    ans = []

    def bt(curr, candidates):
        if len(curr) == len(s) and curr not in added:
            nonlocal count
            added.add(curr)
            count += 1
            ans.append(curr)
            return
        else:
            for i in range(len(candidates)):
                bt(curr + candidates[i], candidates[:i] + candidates[i + 1:])
    
    bt("", sorted(s))
    print(count)
    for i in ans:
        print(i)

main()
