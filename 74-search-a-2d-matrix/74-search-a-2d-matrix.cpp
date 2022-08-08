class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(!matrix.size()) return false;
        int n=matrix.size();//rows no
        int m=matrix[0].size();//cols no
        int lo=0;
        int hi=n*m -1;
        while(lo<=hi){
            int mid=lo+ (hi-lo)/2;//to control overflow condition
            if(matrix[mid/m][mid%m]==target){
                return true;
            }
            if(matrix[mid/m][mid%m]>target){
                hi=mid-1;
            }else{
                lo =mid+1;
            }
        }
        return false;
    }
};