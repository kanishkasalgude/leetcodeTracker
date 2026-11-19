class Solution {
public:
    string digitSum(string s, int k) {
        string temp = s;
        while(temp.size() > k){
            string t = "";
            for(int i=0;i<temp.size();i+=k){
            int sum = 0;
            for(int j=0;j<k && (i+j) < temp.size();j++){
                sum += temp[i+j] - '0';
            }
            t = t + to_string(sum); 
            }
            temp = t;
        }
        return temp;
    }
};
