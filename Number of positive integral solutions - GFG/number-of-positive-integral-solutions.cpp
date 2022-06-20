// { Driver Code Starts
#include <iostream>
using namespace std;


 // } Driver Code Ends
class Solution{
public:
    int fact(int n) {
        if ((n==0)||(n==1))
            return 1;
        else
            return n*fact(n-1);
    }

    long posIntSol(string s)
    {
        int r = 1;
        int n = 0;
        string n_str = "";
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '='){
                i++;
                while(i < s.length()){
                    n_str += s[i];
                    i++;
                }
            }
            else if(s[i] == '+'){
                r++;
            }
        }
        n = stoi(n_str);
        // number of solutins => (n-1)C(r-1)
        n--; r--;

        if(n > 0 && r > 0 && n>=r){
            long long int sol = 1;
            for(int i = n; i > n-r; i--){
                sol *= i;
            }
            sol /= fact(r);
            return sol;
        }
        else{
            return 0;
        }
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.posIntSol(s)<<endl;
    }
    return 0;
}
  // } Driver Code Ends