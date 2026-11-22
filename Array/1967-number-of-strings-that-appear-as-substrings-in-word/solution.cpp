class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int cnt = 0;
        bool find;
        for(int i=0;i<patterns.size();i++){
            find = false;
            int m = patterns[i].size();
            int n = word.size();
            for(int j=0;j<=n-m;j++){
                int p = 0;
                while(p<m && word[j+p] == patterns[i][p]) p++;
                if(p==m){
                    find = true;
                    break;
                }
            }
            if(find) cnt++; 
        }
        return cnt;
    }
};
