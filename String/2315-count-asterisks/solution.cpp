class Solution {
public:
    int countAsterisks(string s) {
        string d;

        int cnt = 0;
        bool inBars = false;
        for(auto c : s){
            if(c == '|') inBars = !inBars;
            else if(c == '*' && !inBars) cnt++;
        }
        return cnt;
    }
};
