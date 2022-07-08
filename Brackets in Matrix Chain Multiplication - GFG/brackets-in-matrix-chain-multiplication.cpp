// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
    int **dp;
    string s="";
    public:
    void display(int i,int j){
        if(i==j){
            s+=i+'A';
            return;
        }
        s+="(";
        display(i,dp[j][i]);
        display(dp[j][i]+1,j);
        s+=")";
    }
    string matrixChainOrder(int p[], int n){
        dp = new int *[n];
        for(int i=0;i<n;i++) dp[i]=new int[n];
        
        for(int l=2;l<n;l++){
            for(int i=0;i<=n-l-1;i++){
                int end = i+l-1;
                dp[i][end]=INT_MAX;
                for(int j=i;j<end;j++){
                    int cal = dp[i][j]+dp[j+1][end] + p[i]*p[j+1]*p[end+1];
                    if(cal<dp[i][end])
                        dp[i][end]=cal, dp[end][i]=j;
                }
            }
        }
        display(0,n-2);
        return s;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int p[n];
        for(int i = 0;i < n;i++)
            cin>>p[i];
        
        Solution ob;
        cout<<ob.matrixChainOrder(p, n)<<"\n";
    }
    return 0;
}  // } Driver Code Ends