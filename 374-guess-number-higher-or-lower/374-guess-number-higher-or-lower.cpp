int guess(int num);
class Solution {
public:
    int guessNumber(int n) {
        int low = 1, high = n;
        int mid;
        while (low <= high) {
            mid = low + (high - low) / 2;
            if (guess(mid) == 0) return mid;
            else if (guess(mid) ==-1) high = mid - 1;
            else low = mid + 1;
        }
               
        return mid;
    }
};