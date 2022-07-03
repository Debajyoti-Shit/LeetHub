// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minVal(int a, int b) {
        //check the case if set bits(A)==set bits in(B)
        int A=a,B=b;
        int countA=0,countB=0;
        while(A){
            A=A&(A-1);
            countA++;
        }
        while(B){
            B=B&(B-1);
            countB++;
        }
        if(countA==countB) return a;
        int x=0;
        stack<short int>s;
        //push the binary of number in stack
        while(a){
           s.push(a%2);
           a=a/2;
        }
        while(!s.empty()){
             int rem=s.top();
            if(rem==1 && countB){
                //if it is set and count of set bit is less
                x=x<<1;
                x+=1;
                countB--;
            }
            else{
                x=x<<1;
            }
             s.pop();
        }
        if(!countB){
        return x;
        }
        else{
        //if number of bits is not equal to B 
            int i=1;
            while(countB){
                //traverse from lsb and add 1 if it is 0
                if((x & i)==0) {
                    x+=i;
                    countB--;
                    }
                else{
                    i++;
                }
        }
    return x;
        }
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;

        Solution ob;
        cout << ob.minVal(a, b);

        cout << "\n";
    }

    return 0;
}  // } Driver Code Ends