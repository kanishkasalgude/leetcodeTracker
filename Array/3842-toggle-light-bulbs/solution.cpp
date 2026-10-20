class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        map<int, int>mpp;
        for(int i=0; i<bulbs.size();i++){
            mpp[bulbs[i]]++;
        }
            vector<int>ans;
        for(int i=0;i<mpp.size();i++){
            if(mpp[i]%2==1) ans.push_back(i);
        }
        for(int i=1; i<ans.size();i++){
            for(int j=i; j<ans.size();j++){
                if(ans[j]<ans[j-1]) swap(ans[j],ans[j-1]);
            }
        }
    return ans;
    }
};
