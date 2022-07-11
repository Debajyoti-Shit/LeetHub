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
    vector<int>ans;
    void dfs(TreeNode* root, int height){
        if(root==NULL) return;
        if(height==ans.size()) ans.push_back(root->val);
        dfs(root->right, height+1);
        dfs(root->left, height+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        dfs(root,0);
        return ans;
    }
};