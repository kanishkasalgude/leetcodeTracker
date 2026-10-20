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
    int cntinc(TreeNode *temp, int& cnt, int maxi){
        if(temp->left != NULL && temp->right != NULL){
            int x = cntinc(temp->left, cnt, maxi);
            int y = cntinc(temp->right, cnt, maxi);
            maxi = max(x, y);
            if(temp->val >= maxi && temp->val >= maxi){
                cnt++;
                maxi = temp->val;
            }
        }else if(temp->right == NULL && temp->left != NULL){
            maxi = cntinc(temp->left,cnt, maxi);
            if(temp->val >= maxi){
                cnt++;
                maxi = temp->val;
            }
        }else{
            cnt = cnt + 1;
            maxi = max(maxi, temp->val);
        }
        return maxi;
    }
    int countDominantNodes(TreeNode* root) {
        int cnt = 0;
        int maxi = INT_MIN;
        TreeNode *temp = root;
        cntinc(temp, cnt, maxi);
        return cnt;
    }
};
