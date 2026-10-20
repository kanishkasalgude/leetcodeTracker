class Solution {
public:
    long long maximumValue(int n, int s, int m) {
        if(n == 1) return s;
        long long arr[n];
        arr[0] = s;
        for(int i=1;i<n;i++){
            if(i%2 == 0) arr[i] = arr[i-1]-1;
            else arr[i] = arr[i-1]+m;
        }
        return arr[n-1];
    }
};
