// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
//User function template 

class Solution{
 public:
   
   int fun(string &s) {
      int n=s.size();
      long long mod=1e9+7, ca=0,cb=0,cc=0;
      for(int i=0;i<n;i++)
      {
          if(s[i]=='a')
               ca=(2*ca + 1)%mod;
           else if(s[i]=='b')
               cb=(2*cb + ca)%mod;
           else 
               cc= (2*cc + cb)%mod;
      }
      return cc;
      
   }
};

// { Driver Code Starts.
 
int main()
 {
    int t;
    cin>>t;
    while(t--) {
        string s;
        cin>>s;
        Solution obj;
        cout<<obj.fun(s)<<endl;
    }
	return 0;
}  // } Driver Code Ends