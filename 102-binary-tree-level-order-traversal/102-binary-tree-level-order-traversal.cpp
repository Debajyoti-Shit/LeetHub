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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==NULL) return ans;//if root is NULL then return
        
        queue<TreeNode*>q;//for storing nodes
        q.push(root);//push root initially to the queue
       
        while(!q.empty()){//while queue is not empty go and follow few steps
            vector<int>v;//for storing nodes at the same level
            int qlen=q.size();//storing queue size for while loop
            
            for(int i=0;i<qlen;i++){
                TreeNode *temp=q.front();//store front node of queue  and 
                q.pop();//pop it from queue
                v.push_back(temp->val);//push it to v
                //if left subtree exist for temp then store it into the queue
                if(temp->left!=NULL) q.push(temp->left);
                //if right subtree exist for temp then store it into the queue
                if(temp->right!=NULL) q.push(temp->right);
            }
            ans.push_back(v);//push v into answer,
        }
        return ans;
    }
};