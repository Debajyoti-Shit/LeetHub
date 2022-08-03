class Solution {
public:
    bool isPerfectSquare(int num) {
        int lo=1, hi=num/2;
        if(num==1) return true;
        while(lo<=hi){
            long long int mid= lo +(hi-lo)/2;
            long long int midSqr=mid*mid;
            if(midSqr==num) return true;
            else if(midSqr > num) hi=mid-1;
            else lo=mid+1;
        }
        return false;
    }
};