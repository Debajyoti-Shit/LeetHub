// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int catchThieves(char arr[], int n, int k) {
        queue<int>police; // queue to store index of police
        queue<int>chor;// queue to store index of thief
        
        for(int i=0;i<n;i++){
            if(arr[i]=='P'){
                police.push(i);
            }
            else{
                chor.push(i);
            }
        }
        int ans=0;
        while(police.empty()==false && chor.empty()==false){
            if(abs(police.front()- chor.front())<=k){//  if thief is within the reach of the policeman
                ans++;
                police.pop();
                chor.pop();
            }
            else if(police.front()<chor.front()){
            //// thief lies beyond the reach of the current policeman
                police.pop();
            }
            else{// thief is not reachable from any of the police
            //So pop thief
                chor.pop();
            }
        }
        return ans;
    }
};

// { Driver Code Starts.

int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n, k;
		cin>>n >> k;
		char arr[n];
		for (int i = 0; i < n; ++i)
			cin>>arr[i];
		Solution obj;
		cout<<obj.catchThieves(arr, n, k) << endl;
	}
	return 0; 
} 

  // } Driver Code Ends