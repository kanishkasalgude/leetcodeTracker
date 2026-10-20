/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */

class NodeValue{
    int maxNode, minNode, maxSum;
    NodeValue(int minNode, int maxNode, int maxSum){
        this.maxNode = maxNode;
        this.minNode = minNode;
        this.maxSum = maxSum;
    }
};

class Solution {
    int ans = 0;

    private NodeValue helper(TreeNode root){
        if(root == null) return new NodeValue(Integer.MAX_VALUE, Integer.MIN_VALUE, 0);

        NodeValue left = helper(root.left);
        NodeValue right = helper(root.right);

        if(left.maxNode < root.val && right.minNode > root.val){
            int cursum = root.val + left.maxSum + right.maxSum;
            ans = Math.max(cursum, ans);
            return new NodeValue(Math.min(root.val, left.minNode), Math.max(root.val, right.maxNode), cursum);
        }

        return new NodeValue(Integer.MIN_VALUE, Integer.MAX_VALUE, 0);
    }

    public int maxSumBST(TreeNode root) {
        helper(root);
        return ans;
    }
}
