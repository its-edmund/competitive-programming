s = input()

count = 0

def dfs(path, location, visited):
    global count
    if len(path) == 0 and location == (6, 0):
        count += 1
        return
    if len(path) == 0:
        return
    neighbors = [(1, 0), (-1, 0), (0, 1), (0, -1)]
    valid = [0] * 4
    for i in range(4):
        offset_y, offset_x = neighbors[i]
        new_y = location[0] + offset_y
        new_x = location[1] + offset_x
        if 0 <= new_y < 7 and 0 <= new_x < 7 and (new_y, new_x) not in visited:
            valid[i] = 1
    if (valid[0] == 1 and valid[1] == 1 and valid[2] == 0 and valid[3] == 0) or (valid[0] == 0 and valid[1] == 0 and valid[2] == 1 and valid[3] == 1):
        return

    # if path[0] == "?":
    for new_y, new_x in [(location[0] + 1, location[1]), (location[0] - 1, location[1]), (location[0], location[1] + 1), (location[0], location[1] - 1)]:
        if 0 <= new_y < 7 and 0 <= new_x < 7 and (new_y, new_x) not in visited:
            visited.add((new_y, new_x))
            dfs(path[1:], (new_y, new_x), visited)
            visited.remove((new_y, new_x))
    # else:
    #     new_y = location[0]
    #     new_x = location[1]
    #     if path[0] == "R":
    #         new_x += 1
    #     elif path[0] == "L":
    #         new_x -= 1
    #     elif path[0] == "U":
    #         new_y -= 1
    #     elif path[0] == "D":
    #         new_y += 1
    #     if 0 <= new_y < 7 and 0 <= new_x < 7 and (new_y, new_x) not in visited:
    #         visited.add((new_y, new_x))
    #         dfs(path[1:], (new_y, new_x), visited)
    #         visited.remove((new_y, new_x))


dfs(s, (0, 0), set())
print(count)
