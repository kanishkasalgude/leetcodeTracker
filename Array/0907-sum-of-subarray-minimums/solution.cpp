class Solution {
public:
    vector<int> findNSE(vector<int> arr){
        vector<int> nse(arr.size());
        stack<int> st;
        int n = arr.size();
        for(int i = arr.size()-1;i>=0;i--){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            nse[i] = st.empty() ? n : st.top();
            st.push(i); 
        }
        return nse;
    }

    vector<int> findPSEE(vector<int> arr){
        vector<int> psee(arr.size());
        stack<int> st;
        int n = arr.size();
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()] > arr[i]){
                st.pop();
            }
            psee[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return psee;
    }

    int sumSubarrayMins(vector<int>& arr) {
        vector<int> nse = findNSE(arr);
        vector<int> psee = findPSEE(arr);
        long long total = 0;
        int mod = (int)(1e9+7);

        int left = 0;
        int right = 0;

        for(int i=0;i<arr.size();i++){
            left = i - psee[i];
            right = nse[i] - i;
            total = (total + (1LL*left*right*arr[i])%mod)%mod;
        }
        return total;
    }
};
