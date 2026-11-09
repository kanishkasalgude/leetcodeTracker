class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        set<int> available;
        for(int i=0;i<k;i++){
            available.insert(i);
        }
        using P = pair<long long, int>;
        priority_queue<P, vector<P>, greater<P>>busy;
        vector<int> request_count(k,0);
        for(int i=0;i<arrival.size();i++){
            long long cur_time = arrival[i];

            while(!busy.empty() && busy.top().first <= cur_time){
                available.insert(busy.top().second);
                busy.pop();
            }

            if(available.empty()) continue;

            int target = i%k;
            auto it = available.lower_bound(target);
            if(it == available.end()){
                it = available.begin();
            }
            int server_id = *it;
            available.erase(it);
            request_count[server_id]++;
            busy.push({cur_time+load[i], server_id});
        }
        int max_request = *max_element(request_count.begin(), request_count.end());
        vector<int> ans;
        for(int i=0;i<k;i++){
            if(request_count[i] == max_request) ans.push_back(i);
        }
        return ans;
    }
};
