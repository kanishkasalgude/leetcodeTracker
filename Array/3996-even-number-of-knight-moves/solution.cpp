class Solution {
public:
    bool isBlack(vector<int>s){
        if(((s[0] % 2 == 0)&&(s[1] % 2 == 0))||((s[0] % 2 != 0)&&(s[1] % 2 != 0))) return true;
        else return false;
    }
    bool canReach(vector<int>& start, vector<int>& target) {
        if(isBlack(start)) return isBlack(target);
        else return !isBlack(target);
    }
};
