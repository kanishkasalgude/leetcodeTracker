class Solution(object):
    def minCostConnectPoints(self, points):
        """
        :type points: List[List[int]]
        :rtype: int
        """
        n = len(points)
        if n <= 1:
            return 0

        min_heap = [(0,0)]
        visited = set()
        total_cost = 0

        while len(visited)<n:
            cost, u = heapq.heappop(min_heap)
            if u in visited:
                continue
            visited.add(u)
            total_cost+=cost
            x1, y1 = points[u]
            for v in range(n):
                if v not in visited:
                    x2, y2 = points[v]
                    manhattan_dist = abs(x1-x2)+abs(y1-y2)
                    heapq.heappush(min_heap,(manhattan_dist, v))

        return total_cost
        
