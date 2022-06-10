// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int maxCoins(int A[], int B[], int T, int N) {
        vector<pair<int,int>> plat;
        for(int i=0;i<N;i++){
            plat.push_back(make_pair(B[i],A[i]));
        }
        sort(plat.begin(),plat.end());
        int profit=0;
        int i=N-1;
        for(;i>=0;i--){
            if(plat[i].second>T){
                break;
            }    
            profit+=plat[i].first*plat[i].second;
            T-=plat[i].second;
        }
        
        if(T!=0 && i>=0){
            profit+=plat[i].first*T;
        }
        
        return profit;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int T,N;
        cin>>T>>N;
        
        int A[N], B[N];
        
        for(int i=0; i<N; i++)
            cin>>A[i];
        for(int i=0; i<N; i++)
            cin>>B[i];

        Solution ob;
        cout << ob.maxCoins(A,B,T,N) << endl;
    }
    return 0;
}  // } Driver Code Ends