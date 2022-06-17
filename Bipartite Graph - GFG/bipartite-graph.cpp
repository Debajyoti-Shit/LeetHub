// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    bool bfs(int src, vector<char> &color, vector<int> adj[]) {
        //pair -> node,color
        queue<pair<int,char>> q;
        
        q.push({src,'r'});
        color[src] = 'r';
	    
	    while(!q.empty()) {
	       int curNode = q.front().first;
	       int curColor = q.front().second;
	       q.pop();
	       
	       for(int x : adj[curNode]) {
	          if(color[x] == curColor)
	            return false;
	            
	           if(color[x] == '0') {
	               color[x] = (curColor == 'r') ? 'b' : 'r';
	               q.push({x,color[x]});
	           }
	       }
	    }
	    return true;
    }
    
	bool isBipartite(int v, vector<int>adj[]){
	    
	    vector<char> color(v+1,'0');
	    
	    for(int i = 0; i < v; i++) {
	        if(color[i] == '0') {
	            if(!bfs(i,color,adj))
	                return false;
	        }
	    }
	    return true;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}  // } Driver Code Ends