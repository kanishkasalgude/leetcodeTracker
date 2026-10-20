class Solution {
    void backtrack(string res, int open, int close, int n, vector<string> &ans){
        if(res.length() == 2*n){
            ans.push_back(res);
            return;
        }
        if(open < n) backtrack(res+'(', open+1, close, n, ans);
        if(close<open) backtrack(res+')', open, close+1, n, ans);
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        backtrack("", 0, 0, n, ans);
        return ans;
    }
};
