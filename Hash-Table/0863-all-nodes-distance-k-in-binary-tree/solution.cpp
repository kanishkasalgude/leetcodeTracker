/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    void getparent(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parent_node, TreeNode* target){
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(node->left){
                parent_node[node->left] = node;
                q.push(node->left);
            }
            if(node->right){
                parent_node[node->right] = node;
                q.push(node->right);
            }
        }
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*>parent_node;
        getparent(root,parent_node, target);
        unordered_map<TreeNode*, bool>visited;
        queue<TreeNode*>q;
        q.push(target);
        visited[target] = true;
        int dist = 0;
        while(!q.empty()){
            int size = q.size();
            if(dist == k) break;
            dist++;
            for(int i=0; i<size; i++){
                TreeNode* node = q.front();q.pop();
                if(node->left && !visited[node->left]){
                    q.push(node->left);
                    visited[node->left] = true;
                }
                if(node->right && !visited[node->right]){
                    q.push(node->right);
                    visited[node->right] = true;
                }
                if(parent_node[node] && !visited[parent_node[node]]){
                    q.push(parent_node[node]);
                    visited[parent_node[node]] = true;
                }
            }
        }
        vector<int>ans;
        while(!q.empty()){
            TreeNode* n = q.front();
            q.pop();
            ans.push_back(n->val);
        }
        return ans;
        
    }
};
