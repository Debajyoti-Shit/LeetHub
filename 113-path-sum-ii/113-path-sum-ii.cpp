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
 
class Solution {
public:
    void getAllPaths(TreeNode *root,int targetSum,vector<int> temp,vector<vector<int>> &ans)
    {
        if(!root) return;
        
        if(!root->left && !root->right && targetSum == root->val){
            temp.push_back(root->val);
            ans.push_back(temp);
            return;
        }
        temp.push_back(root->val);
        getAllPaths(root->left,targetSum-root->val,temp,ans);
        getAllPaths(root->right,targetSum-root->val,temp,ans);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        getAllPaths(root,targetSum,{},ans);
        return ans;
    }
};
*/
class Solution {
public:
    vector<vector<int>> result;
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        //vector<vector<int>> result;
        vector<int> trace;
        if (root==NULL) return result;
        aux(root, sum, trace);
        return result;
    }
    
    void aux(TreeNode *root, int sum, vector<int> trace) {
        
        trace.push_back(root->val);
        if (root->left!=NULL) {
            aux(root->left, sum-root->val, trace);
        }
        if (root->right!=NULL) {
            aux(root->right, sum-root->val, trace);
        }
        if (root->left==NULL && root->right==NULL) {
            if (root->val == sum) {
                result.push_back(trace);
            }
        }
    }
};
