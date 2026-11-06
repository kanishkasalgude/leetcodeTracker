class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        sort(logs.begin(), logs.end(),[](const vector<int>& a, const vector<int>&b){
            return a[1] < b[1];
        });
        int q_len = queries.size();
        vector<pair<int,int>> sorted_queries(q_len);
        for(int i=0;i<q_len;i++){
            sorted_queries[i] = {queries[i], i};
        }
        sort(sorted_queries.begin(), sorted_queries.end());
        int left = 0, right = 0;
        int m = logs.size();

        vector<int> ans(q_len,0);
        vector<int> server_freq(n+1,0);
        int active_servers = 0;

        for(const auto& [q_time, orig_idx]:sorted_queries){
            int start_time = q_time - x;
            int end_time = q_time;

            while(right<m && logs[right][1] <= end_time){
                int s_id = logs[right][0];
                if(server_freq[s_id] == 0){
                    active_servers++;
                }
                server_freq[s_id]++;
                right++;
            }

            while(left < m && logs[left][1] < start_time){
                int s_id = logs[left][0];
                server_freq[s_id]--;
                if(server_freq[s_id] == 0){
                    active_servers--;
                }
                left++;
            }
            ans[orig_idx] = n - active_servers;
        }
        return ans;
    }
};
