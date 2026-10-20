/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    pair<int, int> dfs(TreeNode *root, int &matchingCount){
        if(!root) return {0,0};

        auto left = dfs(root->left, matchingCount);
        auto right = dfs(root->right, matchingCount);

        int currentSum = left.first + right.first + root->val;
        int currentCount = left.second + right.second + 1;

        if(currentSum / currentCount == root->val){
            matchingCount++;
        }

        return {currentSum, currentCount};
    }
public:
    int averageOfSubtree(TreeNode* root) {
        int matchingCount = 0;
        dfs(root, matchingCount);
        return matchingCount;
    }
};
