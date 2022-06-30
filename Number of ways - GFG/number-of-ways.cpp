// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    long long int solve(long long int i,vector<long long int>&dp){
        if(i< 4) return 1;
        if(dp[i]!=-1) return dp[i];
        return dp[i]=solve(i-1,dp)+solve(i-4,dp);
    }
    long long int arrangeTiles(int n){
        vector<long long int>dp(n+1,-1);
        return solve(n,dp);
        
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        cout<<ob.arrangeTiles(N)<<"\n";
    }
    return 0;
}  // } Driver Code Ends