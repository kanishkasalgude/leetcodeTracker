#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();
        
        // Build adjacency list for the original tree
        vector<vector<int>> orig_adj(n);
        for (int i = 1; i < n; ++i) {
            orig_adj[parent[i]].push_back(i);
        }
        
        vector<int> new_parent = parent;
        // Tracks the most recent ancestor for each character 'a'-'z'
        vector<int> last_seen(26, -1);
        
        // Phase 1: Find closest ancestor with the same character
        auto dfs_reparent = [&](auto& self, int u) -> void {
            int char_idx = s[u] - 'a';
            int prev_ancestor = last_seen[char_idx];
            
            if (prev_ancestor != -1) {
                new_parent[u] = prev_ancestor;
            }
            
            last_seen[char_idx] = u;
            for (int v : orig_adj[u]) {
                self(self, v);
            }
            
            // Backtrack
            last_seen[char_idx] = prev_ancestor;
        };
        
        dfs_reparent(dfs_reparent, 0);
        
        // Build adjacency list for the modified tree
        vector<vector<int>> new_adj(n);
        for (int i = 1; i < n; ++i) {
            new_adj[new_parent[i]].push_back(i);
        }
        
        vector<int> answer(n, 0);
        
        // Phase 2: Compute subtree sizes on the new tree
        auto dfs_size = [&](auto& self, int u) -> int {
            int size = 1;
            for (int v : new_adj[u]) {
                size += self(self, v);
            }
            answer[u] = size;
            return size;
        };
        
        dfs_size(dfs_size, 0);
        return answer;
    }
};
