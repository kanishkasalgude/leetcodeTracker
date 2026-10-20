class Solution {
public:
    bool isPalindrome(string s) {
        string alpha = "";
        for( char c : s){
            if(isalpha(c)) alpha += tolower(c);
            if(isdigit(c)) alpha += c;
        }

        string dup = alpha;
        reverse(alpha.begin(), alpha.end());

        if(alpha == dup) return true;
        return false;
    }
};
