class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        if(s.length() == 1) return false;
        if(s[0] == ')' || s[0] == '}' || s[0] == ']') return false;
        for(char i:s){
            if(i == '(' || i == '[' || i == '{'){
                st.push(i);
            }else{
                if(st.empty()) return false;
                if(i == ')' && st.top() == '('){
                    st.pop();
                }else if(i == ']' && st.top() == '['){
                    st.pop();
                }else if(i == '}' && st.top() == '{'){
                    st.pop();
                }else if(i == ')' || i == ']' || i == '}'){
                    return false;
                }
            }
        }
        if(st.empty()) return true;
        else return false;
    }
};
