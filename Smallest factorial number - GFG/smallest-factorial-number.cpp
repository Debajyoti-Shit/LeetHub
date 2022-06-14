// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution
{
    public:
        int findNum(int n){
            int low = 0, high = 5*n;
            while(low <= high){
                int mid = low + (high - low)/2;
                int cnt = 0;
                int temp = mid;
                while(mid){
                    cnt += mid/5;
                    mid /= 5;
                }
                if(cnt >= n) high = temp - 1;
                else low = temp + 1;
            }
            return low;
        }
};

// { Driver Code Starts.


int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        Solution ob;
        cout <<ob.findNum(n) << endl;
    }
return 0;
}  // } Driver Code Ends