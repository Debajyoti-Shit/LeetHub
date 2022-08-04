class Solution {
public:
    int mySqrt(int x) {
        if(x==0 || x==1) return x;
        int lo=1,hi=x>>1;
        while(lo<=hi){
            long long int mid=lo + (hi-lo)/2;
            if(mid *mid <= x && (mid+1)*(mid+1) >x) return mid;
            else if(mid* mid < x) lo=mid+1;
            else hi=mid-1;
        }
        return -1;
    }
};