class Solution {
public:
    vector<bool> transformStr(string s, vector<string>& strs) {
        vector<bool> ans;
        int one = 0;
        int zero = 0;
        for(int i=0;i<s.length();i++){
            if(s[i] == '1') one++;
            else if(s[i] == '0') zero++;
        }
        int sone, szero;
        for(int i=0; i<strs.size();i++){
            sone = 0;
            szero = 0;
            for(int j=0; j<strs[i].length();j++){
                if(strs[i][j] == '1') sone++;
                else if(strs[i][j] == '0') szero++;
            }

            if(sone > one) ans.push_back(false);
            else if(szero > zero) ans.push_back(false);
            else ans.push_back(true);
        }
        return ans;
    }
};
