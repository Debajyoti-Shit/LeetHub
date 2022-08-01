/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int lo=1,hi=n,mid;
        while(lo<=hi){
            mid= (hi-lo)/2 + lo;
            int pick= guess(mid);
            if(pick==0) return mid;
            else if(pick==1) lo=mid+1;
            else hi=mid-1;
        }
        return mid;
    }
};