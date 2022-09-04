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
    map<vector<int>,vector<int>> mp;
    int maxRow=0,minCol=0,maxCol=0;
    void traverse(TreeNode* root, int col, int row){
        if(root==NULL)  return;
        maxRow=max(maxRow, row);
        minCol=min(col,minCol);
        maxCol=max(col, maxCol);
        mp[{row,col}].push_back(root->val);
        traverse(root->left, col-1, row+1);
        traverse(root->right, col+1, row+1);
        
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        traverse(root, 0,0);
        
        vector<vector<int>> ans;
        for(int j=minCol; j<=maxCol;j++){
            vector<int> temp;
            for(int i=0;i<=maxRow; i++){
                sort(mp[{i,j}].begin(),mp[{i,j}].end());
                for(auto k:mp[{i,j}])
                    temp.push_back(k);
            }  
            ans.push_back(temp);
        }    
        
        
        return ans;
    }
};