class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        int n= nums.size();
        if(n==1) return nums[0];
        unordered_map<int,int>freq;
        for(int i=0; i<n; i++){
            freq[nums[i]]++;
        }
        if(freq.size()==1) return nums[0];
        vector<int>ans;
        for(int i=0;i<freq.size();i++){
            if(freq[i]!=0) ans.push_back(i);
        }
        map<int,int>ans_fre;
        for(int i=0; i<ans.size();i++){
            ans_fre[ans[i]]++;
        }
        int q=-1;
        for(int i=0;i<ans_fre.size();i++){
            if(ans_fre[i]==1) q=i;
        }
        if(q==-1) return -1;
        //int ans_index = ans[ans_fre[i]];
        int ans_index=-1;
        for(int i=0;i<ans.size();i++){
            if(ans[i]==q) ans_index = i; 
        }
        for(int i=0;i<freq.size();i++){
            if(freq[i]==ans_index) return i;
        }
        return -1;
    }
};
