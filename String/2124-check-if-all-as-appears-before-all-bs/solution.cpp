class Solution {
public:
    bool checkString(string s) {
        int check = 0;
        for(auto i:s){
            if(check == 1 && i == 'a') return false;
            if(i == 'b') check = 1;
        }
        return true;
    }
};
