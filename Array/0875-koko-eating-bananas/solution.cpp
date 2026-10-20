class Solution {
public:
    long maxele(vector<int> &piles){
        long n = piles.size();
        long maxi = INT_MIN;
        for(int i=0; i<n; i++){
            if(piles[i]>maxi) maxi = piles[i];
        }
        return maxi;
    }

    long totalhrs(vector<int>& piles, long hourly){
        long totalhr = 0;
        long n = piles.size();
        for(int i=0; i<n;i++){
            totalhr += ceil((double)piles[i]/hourly);
        }
        return totalhr;
    }

    long minEatingSpeed(vector<int>& piles, long h) {
        long low = 1, high = maxele(piles);
        while(low<=high){
            long mid = low + (high-low)/2;
            long totalhr = totalhrs(piles, mid);
            if(totalhr<=h){
                high = mid-1;
            }else low = mid+1;
        }
        return (int)low;
    }
};
