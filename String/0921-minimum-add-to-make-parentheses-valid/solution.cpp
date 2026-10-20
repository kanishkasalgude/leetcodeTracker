class Solution {
public:
    int minAddToMakeValid(string s) {
        int open_needed = 0;
        int close_needed = 0;
        for(int i=0;i<s.length();i++){
            if(s[i] == '(') close_needed++;
            else{
                if(close_needed>0) close_needed--;
                else open_needed++;
            }
        }
        return open_needed+close_needed;
    }
};
