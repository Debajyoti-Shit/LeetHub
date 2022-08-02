class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int>pq;
        
        int rows=matrix.size();
        int cols=matrix[0].size();
        
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                pq.push(matrix[i][j]);
                if(pq.size()>k) pq.pop();
            }
        }
        return pq.top();
    }
};
/*
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int rows=matrix.size();
        int cols=matrix[0].size();
        int arr[rows*cols], x=0;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                arr[x++]=matrix[i][j];
            }
        }
        sort(arr,arr+(rows*cols));
        return arr[k-1];
    }
};
*/