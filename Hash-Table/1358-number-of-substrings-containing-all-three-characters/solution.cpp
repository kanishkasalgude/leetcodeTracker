class Solution {
public:
    int numberOfSubstrings(string s) {
        int cnt = 0;
        int hash[3] = {-1,-1,-1};
        for(int i=0;i<s.length();i++){
            hash[s[i] - 'a'] = i;
            int mini = min({hash[0],hash[1],hash[2]});
            cnt = cnt + 1 + mini;
        }
        return cnt;
    }
};
