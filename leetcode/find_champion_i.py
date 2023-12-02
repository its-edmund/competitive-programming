class Solution:
    def findChampion(self, grid: List[List[int]]) -> int:
        teams = {}
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if i == j:
                    continue
                if grid[i][j] == 1:
                    teams.add(j)
        for i in range(len(grid)):
            if i not in teams:
                return i
