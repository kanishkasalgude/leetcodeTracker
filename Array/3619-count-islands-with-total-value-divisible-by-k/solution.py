from collections import deque

class Solution:
    def countIslands(self, grid: list[list[int]], k: int) -> int:
        m, n = len(grid), len(grid[0])
        
        ans = 0
        for i in range(m):
            for j in range(n):
                if grid[i][j] > 0:
                    s = grid[i][j]
                    q = deque([(i, j)])
                    grid[i][j] = 0  # mark visited
                    
                    while q:
                        x, y = q.popleft()
                        for di, dj in ((1,0),(-1,0),(0,1),(0,-1)):
                            nx, ny = x + di, y + dj
                            if 0 <= nx < m and 0 <= ny < n and grid[nx][ny] > 0:
                                s+=grid[nx][ny]
                                grid[nx][ny] = 0  # mark visited on enqueue
                                q.append((nx, ny))
                    
                    if s % k == 0:
                        ans += 1
        return ans   
