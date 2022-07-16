// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/*You are required to complete this method */

class Solution{
  public:
    bool isPartPos(int a[], int n, int k, int reqd_sum, int cur_sum, int mask){
    if(k == 1)
        return true ;
    if(cur_sum > reqd_sum)
        return false ;
    if(cur_sum == reqd_sum)
        return isPartPos(a,n,k-1,reqd_sum,0,mask) ;
    bool ans = false ;
    for(int i=0; i<n && !ans; i++){
        if((mask & (1<<i)) == 0)
            ans |= isPartPos( a, n, k, reqd_sum, cur_sum + a[i], (mask|(1<<i)) ) ;
    }
    return ans ;
}

bool isKPartitionPossible(int a[], int n, int k){
    int sum = 0 ;
    for(int i=0; i<n; i++)
        sum += a[i] ; 
    
    if(sum % k)
        return false ;

    return isPartPos(a,n,k,sum/k,0,0) ;
}
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	
    	cin>>n;
    	int a[n];
    	for(int i=0;i<n;i++)
    	cin>>a[i];
    	int k;
    	cin>>k;
    	Solution obj;
    	cout<<obj.isKPartitionPossible(a, n, k)<<endl;
    }
}  // } Driver Code Ends