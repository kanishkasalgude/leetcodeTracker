class Solution {
public:
    vector<int> findPSE(vector<int> arr){
        int n = arr.size();
        vector<int> pse(n);
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>arr[i]){
                st.pop();
            }
            if(st.empty()) pse[i] = -1;
            else pse[i] = st.top();
            st.push(i);
        }
        return pse;
    }

    vector<int> findNSEE(vector<int> arr){
        int n = arr.size();
        vector<int> nsee(n);
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            if(st.empty()) nsee[i] = n;
            else nsee[i] = st.top();
            st.push(i);
        }
        return nsee;
    }

    int largestRectangleArea(vector<int>& heights) {
        int maxA = INT_MIN;
        int n = heights.size();
        vector<int> pse = findPSE(heights);
        vector<int> nsee = findNSEE(heights);
        for(int i=0;i<n;i++){
            int left = i-pse[i];
            int right = nsee[i]-i-1;
            maxA = max(maxA, (left+right)*heights[i]);
        }
        return maxA;
    }
};
