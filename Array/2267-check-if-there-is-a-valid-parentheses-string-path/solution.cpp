#include<bits/stdc++.h>
using namespace std;
class Solution {
    bool visited[100][100][101];
    bool dfs(vector<vector<char>>& grid, int r, int c, int balance, int m, int n){
        balance += (grid[r][c] == '(' ? 1:-1);

        if(balance < 0) return false;

        if(r==m-1 && c==n-1) return balance == 0;

        if(visited[r][c][balance]) return false;
        visited[r][c][balance] = true;

        if(r+1<m && dfs(grid, r+1,c,balance, m, n)) return true;

        if(c+1<n && dfs(grid,r,c+1,balance,m,n)) return true;

        return false;
    }
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        if((m+n-1)%2 != 0) return false;

        if(grid[0][0] == ')' || grid[m-1][n-1] == '(') return false;

        memset(visited, false, sizeof(visited));
        return dfs(grid, 0, 0, 0, m, n);
    }
};
