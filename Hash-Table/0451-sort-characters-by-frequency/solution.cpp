class Solution {
    static bool comparator(pair<int, char> p1, pair<int, char> p2){
        return p1.first > p2.first;
    }

public:
    string frequencySort(string s) {
        pair<int, char> freq[128];

        for(int i=0; i<128;i++){
            freq[i] = {0, i};
        }

        for(char ch:s){
            freq[ch].first++;
        }

        sort(freq, freq+128, comparator);

        string ans = "";
        for(int i=0; i<128;i++){
            if(freq[i].first>0){
                for(int j=0; j<freq[i].first;j++){
                    ans += freq[i].second;
                }
            }
            
        }

        return ans;
    }
};
