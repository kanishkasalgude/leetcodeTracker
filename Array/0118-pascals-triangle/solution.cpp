class Solution {
public:
    vector<int> generateRow(int row){
        int ans = 1;
        vector<int> rows;
        rows.push_back(ans);
        for(int i=1; i<row; i++){
            ans = ans*(row-i);
            ans = ans/i;
            rows.push_back(ans);
        }
        return rows;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>res;
        for(int i=1; i<=numRows; i++){
            res.push_back(generateRow(i));
        }
        return res;
    }
};
