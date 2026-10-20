#include<bits/stdc++.h>
class Solution {
public:
    string reverseString(string s) {
    string res;
  
  	// Traverse on s in backward direction
  	// and add each charecter to a new string
    for (int i = s.size() - 1; i >= 0; i--) {
        res += s[i];
    }
    return res;
    }
    
    string asc(string s){
        sort(s.begin(), s.end());
        return s;
    }

    string desc(string s){
        string t = s;
        sort(s.begin(), s.end());
        t = reverseString(s);
        return t;
    }
    
    string rearrangeString(string s, char x, char y) {
        string t = s;
        if(x>y){
            t = asc(t);
        }else{
            t = desc(t);
        }

        return t;
    }
};
