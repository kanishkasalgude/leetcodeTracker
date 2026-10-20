class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int maxi = 0; int count = 0;
        for(int i=0; i<accounts.size();i++){
            count = 0;
            for(int j = 0; j<accounts[0].size();j++){
                count += accounts[i][j];
            }
            maxi = max(count, maxi);
        }
        return maxi;
    }
};
