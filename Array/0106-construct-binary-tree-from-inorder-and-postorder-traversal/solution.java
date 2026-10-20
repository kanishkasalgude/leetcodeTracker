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
class Solution {
    public TreeNode buildTree(int[] inorder, int[] postorder) {
        if(postorder == null || inorder == null || inorder.length != postorder.length) return null;
        
        Map<Integer, Integer> inMap = new HashMap<Integer,Integer>();
        for(int i=0; i<inorder.length;i++){
            inMap.put(inorder[i], i);
        }

        return build(postorder,0,postorder.length-1,inorder, 0, inorder.length-1, inMap);
    }

    public TreeNode build(int[] postorder, int pst, int pe, int[] inorder, int inst, int ine, Map<Integer, Integer>inMap){
        if(pst>pe || inst>ine) return null;

        TreeNode root = new TreeNode(postorder[pe]);
        int inRoot = inMap.get(postorder[pe]);
        int numsleft = inRoot-inst;

        root.left = build(postorder, pst, pst+numsleft-1,inorder,inst,inRoot-1,inMap);
        root.right = build(postorder,pst+numsleft,pe-1,inorder, inRoot+1, ine, inMap);
        return root;
    }
}
