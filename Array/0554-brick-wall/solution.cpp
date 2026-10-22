class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        long long rows = wall.size();
        long long width = 0;
        vector<vector<int>> edges(rows);
        unordered_map<long long, int> mpp;
        for(int i=0;i<rows;i++){
            long long sum = 0;
            for(auto it:wall[i]){
                sum += it;
                edges[i].push_back(sum);
                mpp[sum]++;
            }
            width = sum;
        }
        int maxi = 0;
        for(auto it:mpp){
            if(it.first != width){
                maxi = max(maxi, it.second);
            }
        }
        return (int)(rows-maxi);
    }
};
