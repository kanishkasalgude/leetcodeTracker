class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> res;
        string s1 = ".";
        string s2 = ".";
        for(int i=0;i<n-1;i++){
            s1 = s1 + "#";
            s2 = s2 + ".";
        }
        for(int i=0;i<m;i++){
            if(i == m-1) res.push_back(s2);
            else res.push_back(s1);
        }
        return res;
    }
};
