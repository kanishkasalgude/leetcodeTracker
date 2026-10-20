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
    bool go(TreeNode* p, TreeNode* q){
        bool ans = true;
        if(p== NULL && q != NULL) return false;
        if(p!= NULL && q == NULL) return false;
        if(p== NULL && q == NULL) return true;
            if(p->val == q->val){
                ans = go(p->left, q->left);
                if(ans == true) ans = go(p->right,q->right);
            }else ans = false;
        return ans;
    }
    
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return go(p,q);
    }
};
