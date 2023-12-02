class Solution:
    def maximumScoreAfterOperations(self, edges: List[List[int]], values: List[int]) -> int:
        adj = defaultdict(list)
        for i, j in edges:
            adj[i].append(j)
        return self.r(adj, 0, values)[0]
    
    def r(self, adj, node, values):
        if len(adj[node]) == 0:
            return (0, [values[node]])
        children = []
        sums = 0
        for i in adj[node]:
            i_sum, i_children = self.r(adj, i, values)
            children += i_children
            sums += i_sum
        if sum(children) > values[node]:
            return (i_sum + sum(children), [values[node]])
        else:
            return (i_sum + values[node], children)
