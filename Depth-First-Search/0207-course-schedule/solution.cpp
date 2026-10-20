class Solution {
    bool dfs(int node, vector<vector<int>>& adj, vector<int>& vis, vector<int>& pathVis){
        vis[node] = 1;
        pathVis[node] = 1;
        for(auto it:adj[node]){
            if(vis[it] == 0){
                if(dfs(it, adj, vis, pathVis)) return true;
            }else if(pathVis[it]){
                return true;
            }
        }

        pathVis[node] = 0;
        return false;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = prerequisites.size();
        vector<vector<int>> adj(numCourses);
        for(int i=0;i<n;i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        vector<int> indegree(numCourses, 0);
        queue<int>q;

        for(int i=0;i<numCourses;i++){
            for(auto it:adj[i]){
                indegree[it]++;
            }
        }

        for(int i=0;i<numCourses;i++){
            if(indegree[i] == 0) q.push(i);
        }

        vector<int> topo;

        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for(auto it:adj[node]){
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
        }

        if(topo.size() == numCourses) return true;
        return false;
    }
};
