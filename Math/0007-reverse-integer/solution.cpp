class Solution {
public:
    long long reverse(int x) {
        long long y=0;
        bool sign = true;
        x = (long long)x;
        if(x<0) sign = false;
        x = abs(x);
        while(x>0){
            y = (y*10)+(x%10);
            x = x/10;
        }
        if(sign == true)return y;
        else return -y;
    }
};
