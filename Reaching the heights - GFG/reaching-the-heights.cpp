// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


vector<int> reaching_height(int n, int a[]) ;

int main() {
	int t;
	cin >> t;
	while (t-- > 0) {
	    int n; 
	    cin >> n;
	    int a[n];
	    for (int i = 0; i < n; i++) 
	        cin >> a[i];
	    vector<int> v;
	    v = reaching_height(n,a);
	
	    if(v.size()==1 and v[0] == -1){
	        cout << "Not Possible\n";
	    }
	    else{
	    for(int i:v)
	        cout << i << " ";
	    cout << endl;}
	    
	}
	return 0;
}// } Driver Code Ends


//User function Template for C++

vector<int> reaching_height(int n, int a[]) {
    // Complete the function
        sort(a, a+n);
    int i=0,j=n-1,sum=0;
    bool flag = true;
    vector<int> res;
    while(i<=j){
        if(flag == true){
            res.push_back(a[j]);
            sum += a[j--];
            flag = false;
        }
        else{
            res.push_back(a[i]);
            sum += -1 * a[i++];
            flag = true;
        }
        if(sum<=0){
            vector<int> ans;
            ans.push_back(-1);
            return ans;
        }
    }
    return res;

}
