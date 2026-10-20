class Solution {
public:
    int almostPalindromic(string s) {
        int n=s.length();
        if(n<2) return n;
        if(n==2) return 1;
        int i=0;
        int j=n-1;
        int rem1 = 0;
        while(i<=j){
            if(rem1<=2 && s[i]!=s[j]){
                    if(s[i]==s[j-1]){
                        rem1++;
                        j--;
                    }else if(s[i+1]==s[j]){
                        rem1++;
                        i++;
                    }
            }
            if(s[i]!=s[j]) return -1;
            i++; 
            j--;
        }
        if(rem1==2) return n-1;
        return n;
    }
};
