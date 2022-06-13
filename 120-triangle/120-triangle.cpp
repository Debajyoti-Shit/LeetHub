class Solution {
public:
    int helper(vector<vector<int>>& triangle, int i, int j,vector<vector<int>>& dp){
        if(i==triangle.size()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        dp[i][j]=triangle[i][j]+ min(helper(triangle,i+1,j,dp), helper(triangle,i+1,j+1,dp));
        return dp[i][j];
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int i=triangle.size(),j=i;
        vector<vector<int>>dp(i,vector<int>(j,-1));
        return helper(triangle,0,0,dp);
    }
};