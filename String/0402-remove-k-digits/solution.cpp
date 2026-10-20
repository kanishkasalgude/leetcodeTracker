class Solution {
public:
    string removeKdigits(string s, int k) {
        long long n = s.length();
        if(k == n) return "0";
        stack<char> st;
        for(long long i=0;i<n;i++){
            while(!st.empty() && k>0 && (st.top()-'0')>(s[i]-'0')){
                st.pop();
                k--;
            }
            st.push(s[i]);
        }
        while(k>0 && !st.empty()){
            st.pop();
            k--;
        }
        if(st.empty()) return "0";
        string res = "";
        while(!st.empty()){
            res += st.top();
            st.pop();
        }
        while(res.length() != 0 && res.back() == '0') res.pop_back();
        reverse(res.begin(),res.end());
        if(res.empty()) return "0";
        return res;
    }
};
