class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int n = costs.size();

    // find the maximum element
        int maxval = 0;
        for (int i = 0; i < n; i++)
            maxval = max(maxval, costs[i]);

    // create and initialize cntArr array
        vector<int> cntArr(maxval + 1, 0);

    // count frequency of each element
        for (int i = 0; i < n; i++)
            cntArr[costs[i]]++;

    // compute prefix sum
        for (int i = 1; i <= maxval; i++)
            cntArr[i] += cntArr[i - 1];

    // build output array
        vector<int> ans(n);
        for (int i = n - 1; i >= 0; i--) {
            ans[cntArr[costs[i]] - 1] = costs[i];
            cntArr[costs[i]]--;
        }

        int res = 0;
        int i=0;
        while (i < n && coins >= ans[i]) {
            coins -= ans[i];
            res++;
            i++;
        }
        return res;
    }
};
