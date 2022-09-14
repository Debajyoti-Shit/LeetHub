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
    int ans=0;
    unordered_map<int,int>m;
    
    void recurson(TreeNode* root){
        if(root==NULL) return;
        m[root->val]++;
        //if it is leaf node, i.e reached to end, got a path , then check the path 
        if(root->left==NULL && root->right==NULL){
            int odd=0;
            for(auto it : m){
                if(it.second%2==1) odd++;
            }
            if(odd<=1) ans++;
        }
        recurson(root->left);
        recurson(root->right);
        m[root->val]--;
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        recurson(root);
        return ans;
    }
};