/*
class Solution {
    public:
    void solve(int col,vector<string>&board,vector<vector<string>>&ans,vector<int>&leftRow,vector<int>&upperDiagonal,vector<int>&lowerDiagonal,int n){
        if(col==n){
            ans.push_back(board);
            return;
        }
        for(int row=0;row<n;row++){
            if(leftRow[row]==0 && upperDiagonal[n-1+ col-row]==0 && lowerDiagonal[row+col]==0){
                board[row][col]='Q';
                
                leftRow[row]=1;
                upperDiagonal[n-1+col-row]=1;
                lowerDiagonal[row+col]=1;
                
                solve(col+1,board,ans,leftRow,upperDiagonal,lowerDiagonal,n);
                
                board[row][col]='.';//backtrack
                
                leftRow[row]=0;
                upperDiagonal[n-1 + col-row]=0;
                lowerDiagonal[row+col]=0;
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>board(n);
        string s(n, '.');
        for(int i=0;i<n;i++){
            board[i]=s;
        }
        vector<int>leftRow(n,0);
        vector<int>upperDiagonal(2*n-1,0);
        vector<int>lowerDiagonal(2*n-1,0);
        solve(0,board,ans,leftRow,upperDiagonal,lowerDiagonal,n);
        return ans;
        
    }
};





*/

























class Solution {
public:
    
    vector<vector<string>> result;
    bool issafe(vector<string>&board,int x,int y){
       // for check in column
       int n=board.size();
       for(int row=0;row<x;row++){
            if(board[row][y]=='Q'){
                return false;
            }
       }

       // for checking in left diagonal
       int row=x-1,col=y-1;
       while(row>=0 && col>=0){
            if(board[row][col]=='Q'){
                return false;
            }
            row--; col--;
       }

       // for checking in right diagonal
        row=x-1;
        col=y+1;
       while(row>=0 && col<n){
            if(board[row][col]=='Q'){
                return false;
            }
            row--; col++;
       }
        //if all condition satisfied returning true;
       return true;
    }


    void backtrack(int row , int n,vector<string>&curr) {
        if(row == n){
            result.push_back(curr);
            return;
        }
        
        for(int col=0;col<n;col++) {
            if(issafe(curr,row,col)) {
                curr[row][col] = 'Q';
                //recursive call to next row;
                backtrack(row+1,n,curr);
                //backtracting
                //before backtracking we are change the location with previous value 
                curr[row][col] = '.';
            }
        }
        
        return;
    }
     
    vector<vector<string>> solveNQueens(int n) {
        string s;
        for(int i=0;i<n;i++) 
            s.push_back('.');
        vector<string> curr(n,s);
        backtrack(0,n,curr);
        return result;
    }
};
