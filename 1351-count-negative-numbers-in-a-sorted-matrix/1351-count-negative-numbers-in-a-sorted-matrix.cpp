class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int rows=grid.size();
        int cols=grid[0].size();
        int i=0;
        int j=cols-1;
        int cnt=0;
        while((i>=0 && i<rows) && (j>=0&& j<cols)){
            if(grid[i][j]< 0){
                cnt+=rows-i;
                j--;
            }else i++;
        }
        return cnt;
    }
};