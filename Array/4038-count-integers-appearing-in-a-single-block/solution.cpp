class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        unordered_set<int> seen;
        unordered_set<int> invalid;

        for(int i=0;i<n;i++){
            int curr = nums[i];
            if(seen.find(curr) != seen.end()){
                if(invalid.find(curr) == invalid.end()){
                    invalid.insert(curr);
                    cnt--;
                }
            }else{
                seen.insert(curr);
                cnt++;
            }

            while(i+1<n && nums[i+1] == curr) i++;
        }
        return cnt;
    }
};
