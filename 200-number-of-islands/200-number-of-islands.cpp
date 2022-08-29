class Solution {
public:
    void DFS(vector<vector<char>>& grid, int i, int j){
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || grid[i][j]=='0') return;
        
        grid[i][j]='0';
        
        DFS(grid,i+1,j);
        DFS(grid,i-1,j);
        DFS(grid,i,j+1);
        DFS(grid,i,j-1);
    }
    int numIslands(vector<vector<char>>& grid) {
        int ans=0;
        int row=grid.size(), col=grid[0].size();
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]=='1'){
                    ans++;
                    DFS(grid,i,j);
                }
            }
        }
        return ans;
    }
};