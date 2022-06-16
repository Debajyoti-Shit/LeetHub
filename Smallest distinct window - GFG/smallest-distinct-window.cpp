// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    bool isPossible(vector<int>& mask, vector<int>& winMask){
        for(int i = 0; i < 60; i++){
            if(mask[i] > 0 && winMask[i] <= 0) return false;
        }
        return true;
    }
    
    int findSubString(string str){
        vector<int> mask(60, 0), winMask(60, 0);
        for(int c : str){
            mask[c - 'A']++;
        }
        int i = 0, j = 0, n = str.size();
        int ans = n;
        while(j < n){
            winMask[str[j] - 'A']++;
            if(isPossible(mask, winMask)){
                ans = min(ans, j - i + 1);
                while(isPossible(mask, winMask)){
                    ans = min(ans, j - i + 1);
                    winMask[str[i] - 'A']--;
                    i++;
                }
            }
            j++;
        }
        return ans;
    }
};

// { Driver Code Starts.
// Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str) << endl;
    }
    return 0;
}  // } Driver Code Ends