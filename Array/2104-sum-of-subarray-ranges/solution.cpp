class Solution {
public:
    vector<int> findPLE(vector<int> arr){
        int n = arr.size();
        vector<int> ple(n);
        stack<int> st;
        for(int i=0;i<arr.size();i++){
            while(!st.empty() && arr[st.top()] < arr[i]){
                st.pop();
            }
            if(st.empty()) ple[i] = -1;
            else ple[i] = st.top();
            st.push(i);
        }
        return ple;
    }

    vector<int> findPSE(vector<int> arr){
        int n = arr.size();
        vector<int> pse(n);
        stack<int> st;
        for(int i=0;i<arr.size();i++){
            while(!st.empty() && arr[st.top()] > arr[i]){
                st.pop();
            }
            if(st.empty()) pse[i] = -1;
            else pse[i] = st.top();
            st.push(i);
        }
        return pse;
    }

    vector<int> findNLEE(vector<int> arr){
        int n = arr.size();
        vector<int> nlee(n);
        stack<int>st;
        for(int i=arr.size()-1;i>=0;i--){
            while(!st.empty() && arr[st.top()] <= arr[i]) st.pop();
            if(st.empty()) nlee[i] = n;
            else nlee[i] = st.top();
            st.push(i);
        }
        return nlee;
    }

    vector<int> findNSEE(vector<int> arr){
        int n = arr.size();
        vector<int> nsee(n);
        stack<int>st;
        for(int i=arr.size()-1;i>=0;i--){
            while(!st.empty() && arr[st.top()] >= arr[i]) st.pop();
            if(st.empty()) nsee[i] = n;
            else nsee[i] = st.top();
           st.push(i);
        }
        return nsee;
    }
    
    long long subMax(vector<int> arr){
        long long total = 0;
        stack<int> st;
        int n = arr.size();
        vector<int> ple = findPLE(arr);
        vector<int> nlee = findNLEE(arr);
        int left = 0;
        int right = 0;
        for(int i=0;i<n;i++){
            left = i - ple[i];
            right = nlee[i] - i;
            total = total+(1LL*left*right*arr[i]);
        }
        return total;
    }

    long long subMin(vector<int> arr){
        long long total = 0;
        stack<int> st;
        int n = arr.size();
        vector<int> pse = findPSE(arr);
        vector<int> nsee = findNSEE(arr);
        int left = 0;
        int right = 0;
        for(int i=0;i<n;i++){
            left = i - pse[i];
            right = nsee[i] - i;
            total = total+(1LL*left*right*arr[i]);
        }
        return total;
    }

    long long subArrayRanges(vector<int>& nums) {
        return subMax(nums) - subMin(nums);
    }
};
