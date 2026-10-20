class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int org = image[sr][sc];
        if(org == color) return image;
        int n = image.size();
        int m = image[0].size();
        vector<vector<int>> ans = image;
        ans[sr][sc] = color;
        queue<pair<int,int>>q;
        q.push({sr,sc});
        int dr[] = {-1,0,1,0};
        int dc[] = {0,1,0,-1};
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nrow = r + dr[i];
                int ncol = c + dc[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && ans[nrow][ncol] == org){
                    q.push({nrow,ncol});
                    ans[nrow][ncol] = color;
                }
            }
        }
        return ans;
    }
};
