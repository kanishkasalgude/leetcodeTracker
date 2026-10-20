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
public:
    int height(TreeNode* node, int& maxi){
        if(node == NULL) return 0;
        int lh = max(0,height(node->left, maxi));
        int rh = max(0,height(node->right, maxi));
        maxi = max(maxi, lh+rh+node->val);
        return node->val+max(rh, lh);
    }

    int maxPathSum(TreeNode* root) {
        int pathSum = INT_MIN;
        if(root->left == NULL && root->right == NULL) return root->val; 
        height(root, pathSum);
        return pathSum;
    }
};
