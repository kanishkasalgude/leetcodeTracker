class Solution {
public:
    bool isPalindrome(int x) {
        string s = to_string(x);
        string rev = s;
        reverse(s.begin(), s.end());
        if(s == rev) return true;
        return false;
    }
};
