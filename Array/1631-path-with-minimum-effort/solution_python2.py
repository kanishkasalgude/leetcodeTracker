class Solution(object):
    def minimumEffortPath(self, heights):
        """
        :type heights: List[List[int]]
        :rtype: int
        """
        n = len(heights)
        m = len(heights[0])
        pq = [(0,0,0)]
        dist = [[float('inf')]*m for _ in range(n)]
        dist[0][0] = 0

        dr = [-1,0,1,0]
        dc = [0,1,0,-1]

        while pq:
            effort, r, c = heapq.heappop(pq)
            if r == n-1 and c == m-1:
                return effort
            
            if effort > dist[r][c]:
                continue

            for i in range(4):
                nr, nc = r + dr[i], c + dc[i]
                if 0<=nr<n and 0<=nc<m:
                    curr_effort = abs(heights[r][c] - heights[nr][nc])
                    new_effort = max(curr_effort, effort)
                    if new_effort<dist[nr][nc]:
                        dist[nr][nc] = new_effort
                        heapq.heappush(pq, (new_effort, nr, nc))
            
        return 0



        
