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
    int goodNodes(TreeNode* root, int maxval) {
        if(root==NULL) return 0;
        int cnt=0;
        if(root->val >= maxval){
            maxval=root->val;
            cnt++;
        }
        return cnt+ goodNodes(root->left,maxval) + goodNodes(root->right,maxval);
    }
    int goodNodes(TreeNode* root) {
        if(root==NULL) return 0;
        return goodNodes(root,root->val);
    }
};