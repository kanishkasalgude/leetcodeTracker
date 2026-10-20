class Solution {
    public String removeOuterParentheses(String s) {
        StringBuilder result = new StringBuilder();
        int length = s.length();
        int level = 0;
        for(char c:s.toCharArray()){
            if(c=='('){
                if(level >0)result.append(c);
                level++;
            }else{
                level--;
                if(level>0) result.append(c);
            }
        }
        return result.toString();
    }
};
