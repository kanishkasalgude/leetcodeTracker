class Solution {
public:
    bool possible(vector<int>& bloomDay, int day, int m, int k){
        int no_of_b = 0;
        int cnt = 0;
        int n = bloomDay.size();
        for(int i=0; i<n; i++){
            if(bloomDay[i]<=day) cnt++;
            else{
                no_of_b += (cnt/k);
                cnt = 0;
            }
        }
        no_of_b += (cnt/k);
        return no_of_b>=m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if(n<(long)m*k) return -1;
        int low = INT_MAX, high = INT_MIN;
        for(int i=0; i<n;i++){
            low = min(low, bloomDay[i]);
            high = max(high, bloomDay[i]);
        }
        while(low<=high){
            int mid = low + (high - low)/2;
            if(possible(bloomDay, mid, m, k) == true) high = mid-1;
            else low = mid + 1;
        }
        return low;
    }
};
