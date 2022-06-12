// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	int solve(string s,int i,int preSumLeft,vector<vector<int> > &dp){
	    if(i==s.length()){
	       return 1;
	    }
	    if(dp[i][preSumLeft]==-1){
    	    dp[i][preSumLeft] = solve(s,i+1,preSumLeft+(s[i]-'0'),dp);
            int sum=0;
            for(int j=i;j<s.length();j++){
                sum+=(s[j]-'0');
                if(sum>=preSumLeft){
                    dp[i][preSumLeft]+= solve(s,j+1,sum,dp);
                    break;
                }
            }
	    }
	    return dp[i][preSumLeft];
	}
	int TotalCount(string str){
	    int sumOfDigits = 0;
	    
	    for(int i=0;i<str.length();i++)
	        sumOfDigits+=(str[i]-'0');
	        
	    vector<vector<int> > dp(str.length(),vector<int>(sumOfDigits+1,-1));

	    return solve(str,1,str[0]-'0',dp);
	}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution ob;
		int ans = ob.TotalCount(str);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends