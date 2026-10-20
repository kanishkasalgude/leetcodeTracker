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
class BSTIteration{
    private:
    stack<TreeNode *> myStack;
    bool reverse = true;

    public:
    BSTIteration(TreeNode *root, bool isReverse){
        reverse = isReverse;
        pushAll(root);
    }

    bool hasnext(){
        return !myStack.empty();
    }

    int next(){
        TreeNode *tempnode = myStack.top();
        myStack.pop();
        if(!reverse) pushAll(tempnode->right);
        else pushAll(tempnode->left);
        return tempnode->val;
    }

    void pushAll(TreeNode *node){
        for(; node != NULL ;){
            myStack.push(node);
            if(reverse == true) node = node->right;
            else node = node->left;
        }
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root) return false;
        BSTIteration l(root, false);
        BSTIteration r(root, true);
        int i = l.next();
        int j = r.next();
        while(i<j){
            if(i+j == k) return true;
            else if(i+j > k) j = r.next();
            else i = l.next();
        }
        return false;
    }
};
