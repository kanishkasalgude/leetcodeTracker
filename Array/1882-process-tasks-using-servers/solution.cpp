class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n = servers.size();
        int m = tasks.size();
        using FreeServers = pair<int, int>;
        priority_queue<FreeServers, vector<FreeServers>, greater<FreeServers>> free_servers;
        for(int i=0;i<n;i++){
            free_servers.push({servers[i], i});
        }

        using BusyServer = tuple<long long, int, int>;
        priority_queue<BusyServer, vector<BusyServer>, greater<BusyServer>> busy_servers;

        vector<int> ans(m);
        long long current_time = 0;
        for(int j=0;j<m;j++){
            current_time = max(current_time, (long long)j);

            while(!busy_servers.empty() && get<0>(busy_servers.top())<=current_time){
                auto [time, weight, idx] = busy_servers.top();
                busy_servers.pop();
                free_servers.push({weight,idx});
            }

            if(free_servers.empty()){
                current_time = get<0>(busy_servers.top());
                while(!busy_servers.empty() && get<0>(busy_servers.top())<=current_time){
                    auto [time, weight, idx] = busy_servers.top();
                    busy_servers.pop();
                    free_servers.push({weight, idx});
                }
            }

            auto [weight, server_idx] = free_servers.top();
            free_servers.pop();
            ans[j] = server_idx;
            busy_servers.push({current_time+tasks[j], weight, server_idx});
        }
        return ans;
    }
};
