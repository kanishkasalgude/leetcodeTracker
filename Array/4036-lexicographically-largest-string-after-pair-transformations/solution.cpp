class Solution {
public:
    vector<string> largestString(vector<int>& nums) {
        int cnt;
        vector<string> res;
        for(int i=0;i<nums.size();i++){
            int c = nums[i];
            int z_count = c>>25;
            int curr = c & ((1<<25)-1);
            string ans = "";
            cnt = 0;
            while(curr!=0){
                if((curr&1) == 1) ans = char('a'+cnt) + ans;
                cnt++;
                curr>>=1;
            }
            ans = string(z_count, 'z')+ans;
            res.push_back(ans);
        }
        return res;
    }
};
