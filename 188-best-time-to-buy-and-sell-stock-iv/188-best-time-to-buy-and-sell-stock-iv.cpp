class Solution {
public:
	int maxProfit(int k, vector<int>& p) {
		int n=p.size();
		vector<vector<int>> dp(n+1,vector<int>(2*k+1,0));
		for(int i=n-1;i>=0;i--){
			for(int tra=2*k-1;tra>=0;tra--){
				int profit;
				if(tra%2==0){
					int buy= -p[i]+dp[i+1][tra+1];
					int notbuy= dp[i+1][tra];
					profit=max(buy,notbuy);
				}
				else{
					int sell= p[i]+dp[i+1][tra+1];
					int notsell= dp[i+1][tra];
					profit=max(sell,notsell);   
				}
				dp[i][tra]=profit;
			}
		}
		return dp[0][0];
	}
};
