class Solution {
public:
    bool judgeSquareSum(int c) {
        long long int lo=0,hi=sqrt(c);
        while(lo<=hi){
            
            if(((lo*lo) + (hi*hi)) == c) return true;
            else if(((lo*lo) + (hi*hi)) > c) hi--;
            else lo++;
        }
        return false;
    }
};