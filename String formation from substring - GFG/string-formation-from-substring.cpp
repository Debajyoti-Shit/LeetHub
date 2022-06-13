// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
		
	int isRepeat(string s){
	    for(int i=1;i<=s.size()/2;i++){
	        if(s.size()%i==0){
	            string str=s.substr(0,i);
	            int repeat=s.size()/i;
	            string str1=str;
	            for(int i=1;i<repeat;i++){
	                str+=str1;
	            }
	            if(str==s) return 1;
	        }
	    }
	    return 0;
	}
};

// { Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string str;
   		cin >> str;
        Solution ob;
   		cout << ob.isRepeat(str) << "\n";
   	}

    return 0;
}  // } Driver Code Ends