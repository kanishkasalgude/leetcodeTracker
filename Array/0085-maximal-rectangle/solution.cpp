class Solution {
public:
    int maxAreaHistogram(vector<int> h){
        int maxArea = 0;
        int n = h.size();
        stack<int> st;
        int nse = 0;
        int pse = 0; 
        int area =0;
        int element = 0;
        for(int i=0;i<n;i++){
            while(!st.empty() && h[st.top()] > h[i]){
                element = st.top();
                st.pop();
                nse = i;
                pse = st.empty()?-1:st.top();
                area = h[element]*(nse-pse-1);
                maxArea = max(area, maxArea);
            }
            st.push(i);
        }
        while(!st.empty()){
            element = st.top();
            st.pop();
            nse = n;
            pse = st.empty()?-1:st.top();
            area = h[element]*(nse-pse-1);
            maxArea = max(area, maxArea);
        }
        return maxArea;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int maxArea = 0;
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> row(m,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j] == '1') row[j]++;
                else row[j] = 0;
            }
            int area = maxAreaHistogram(row);
            maxArea = max(area, maxArea);
        }
        return maxArea;
    }
};
