class Solution {
public:
    /*
    Time Complexity: O(n*logn) // since we are using sorting
    Space Complexity: O(1) // we are not using any additional data structure here
    */
    int bagOfTokensScore(vector<int>& arr, int power) {
        int n = arr.size(); // extract size of array
        
        int score = 0; // intially we have score zero
        
        sort(arr.begin(), arr.end()); // sort the array
        
        int i = 0, j = n - 1; // put two pointers on first and last
        
        // equal sign is not here, because for a single element,
        // we can't use it as to increase score and also use 
        // it as to increase power
        while(i < j) 
        {
            if(power >= arr[i]) // if we have available power to increase score, use it
            {
                power -= arr[i++];
                score++;
            }   
			                                                // for power to be gain, we should have at least one score
            else if(score >= 1 && power + arr[j] >= arr[i]) // and we have to make sure by gaining this power we are able to earn score
                                                           //  else it makes no point of spending score
            {
                power += arr[j--];
                score--;
            }
            else break; // because we already know that array is sorted,
			//so further values wil be definately in increasing order
        }
        
        while(i < j + 1 && power >= arr[i]) // when gap remains, then for that
        {
            power -= arr[i++];
            score++;
        }
        
        return score; // finally return score
    }
};