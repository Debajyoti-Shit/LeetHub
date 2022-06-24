// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    void helper(int level,int pos,bool &ans){
       if(pos==0){return;}
       helper(level,(pos>>1),ans);
       if(pos&1){
           ans=!ans;
       }
   }
   char profession(int level, int pos){
       bool ans=true;
       helper(level,(pos-1),ans);
       if(ans)return 'e';
       else return 'd';
   }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int level, pos;
        cin>>level>>pos;
        
        Solution ob;
        if(ob.profession(level, pos) == 'd')
            cout<<"Doctor\n";
        else
            cout<<"Engineer\n";
    }
    return 0;
}  // } Driver Code Ends