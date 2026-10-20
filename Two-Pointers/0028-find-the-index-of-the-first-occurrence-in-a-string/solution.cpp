class Solution {
public:
    int strStr(string haystack, string needle) {
        for(int i=0;i+needle.size()<=haystack.size();i++){
            if(haystack[i] == needle[0]){
                int k = i;
                for(int j=0;j<needle.size();j++){
                    if(haystack[k] == needle[j]){
                        k++;
                    }
                }
                if(i+needle.size() == k) return i;
            }
        }
        return -1;
    }
};
