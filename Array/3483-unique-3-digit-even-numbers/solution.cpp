class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int count[10] = {0};
        for(int d:digits) count[d]++;
        int validCount = 0;

        for(int d1=1;d1<=9;d1++){
            if(count[d1] == 0) continue;
            count[d1]--;

            for(int d2 = 0;d2<=9;d2++){
                if(count[d2] == 0) continue;
                count[d2]--;

                for(int d3 = 0;d3<=8;d3+=2){
                    if(count[d3]>0){
                        validCount++;
                    }
                }
                count[d2]++;
            }
            count[d1]++;
        }
        return validCount;
    }
};
