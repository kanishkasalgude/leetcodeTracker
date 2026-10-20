class Solution(object):
    def shortestPathBinaryMatrix(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        n = len(grid)
        if grid[0][0] !=0 or grid[n-1][n-1] != 0:
            return -1

        if n==1:
            return 1

        q = deque([(1,0,0)])
        dist = [[float('inf')]*n for _ in range(n)]
        dist[0][0] = 1

        while q:
            dis, r, c = q.popleft()
            if r==n-1 and c==n-1:
                return dis

            for i in range(-1,2):
                for j in range(-1,2):
                    if i == 0 and j == 0:
                        continue
                    
                    newr, newc = r+i, c+j
                    if 0<=newr<n and 0<=newc<n and grid[newr][newc] == 0:
                        if dis+1 < dist[newr][newc]:
                            dist[newr][newc] = dis+1
                            q.append((dis+1,newr,newc))
        
        return -1
        
