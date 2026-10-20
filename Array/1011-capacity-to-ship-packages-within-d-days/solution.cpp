class Solution {
public:
    int func(vector<int>& weights, int cap){
        int days = 0, load = 0;
        for(int i=0;i<weights.size();i++){
            if(load + weights[i] > cap){
                days ++;
                load = weights[i];
            }else{
                load += weights[i];
            }
        }
        return days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int low =INT_MIN;
        int high = 0;
        for(int i=0;i<weights.size();i++){
            low = max(low,weights[i]);
            high += weights[i];
        }
        int daysReq;
        while(low<=high){
            int mid = low + (high - low)/2;
            daysReq = func(weights,mid);
            if(daysReq < days){
                high = mid-1;
            }else low = mid+1;
        }
        return low;
    }
};
