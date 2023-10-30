board = []

for i in range(8):
    board.append(input())

def main():
    count = 0

    def r(board, rows, columns, queens):
        nonlocal count
        if len(queens) == 8:
            count += 1
            return
        for j in range(8):
            if board[len(queens)][j] == "*" or not check(board, queens, (len(queens), j)):
                continue
            rows.add(len(queens))
            columns.add(j)
            queens.append((len(queens), j))
            r(board, rows, columns, queens)
            queens.pop()
            rows.remove(len(queens))
            columns.remove(j)
    r(board, set(), set(), [])
    print(count)

    

def check(board, queens, location):
    for queen in queens:
        if location[0] == queen[0] or location[1] == queen[1] or abs(location[0] - queen[0]) == abs(location[1] - queen[1]):
            return False
    return True

main()
