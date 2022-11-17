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
    public boolean isValidBST(TreeNode root) {
        return isValidBSTSolve(root, Long.MIN_VALUE, Long.MAX_VALUE);
        
        
    }
    
    public boolean isValidBSTSolve(TreeNode root, long min, long max) {
        if(root==null) return true;
        
        if(root.val > min && root.val <  max){
            boolean isLeftBST= isValidBSTSolve(root.left, min, root.val);
            boolean isRightBST= isValidBSTSolve(root.right, root.val, max);
        
            return isLeftBST && isRightBST;
        }
        return false;
    }
    
    
}