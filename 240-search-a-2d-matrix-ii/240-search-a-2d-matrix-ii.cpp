class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows=matrix.size();
        int cols=matrix[0].size();
        
        int i=rows-1, j=0;// starting from bottom-left corner(18 in 1st example)
        while(i>=0 && j<cols){
            if(matrix[i][j]==target) return true;
            else if(matrix[i][j] > target) i--;// if target is smaller, the go up side
            else j++;// if target is greater, then go right side
        }
        return false;
    }
};