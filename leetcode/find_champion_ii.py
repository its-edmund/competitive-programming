class Solution:
    def findChampion(self, n: int, edges: List[List[int]]) -> int:
        indegree = set()
        ans = -1
        for i in edges:
            indegree.add(edges[i][1])
        for i in range(n):
            if i not in indegree and ans == -1:
                ans = i
            elif i not in indegree and ans != -1:
                return -1
        return ans
