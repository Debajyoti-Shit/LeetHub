// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	int TotalWays(int N){
	    
	long long os=1;
    long long ob=1;
    long long mod=1e9+7;
    for(int i=2;i<=N;i++)
    {
        long long nb=os;
        long long ns=ob+os;
        
        os=ns%mod;
        ob=nb%mod;
    }
    long long total=(os+ob)%mod;
    
    return (total*total)%mod;

	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution ob;
		int ans = ob.TotalWays(N);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends