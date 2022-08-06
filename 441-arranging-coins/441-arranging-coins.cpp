class Solution {
public:
    int arrangeCoins(int n) {
        long int lo=1,hi=n;
        long int mid= lo +(hi-lo)/2;
        long int ans=-1;
        while(lo<=hi){
            long int sum= (mid * (mid+1))/2;
            if(sum<=n){
                ans=mid;
                lo=mid+1;
            }else {
                hi=mid-1;
            }
            mid= lo+ (hi-lo)/2;
        }
        return ans;
    }
};