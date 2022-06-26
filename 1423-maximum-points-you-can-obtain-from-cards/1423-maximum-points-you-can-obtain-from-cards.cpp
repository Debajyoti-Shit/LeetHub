class Solution {
public:
    int maxScore(vector<int>& card, int k) {
        int n=card.size();
        int tsum=0;
       for(int i=n-k;i<n;i++){
           tsum+=card[i];
       }
        int maxi=tsum;
         for(int i=0;i<k;i++){
             tsum-=card[n-k+i];
             tsum+=card[i];
             maxi=max(maxi,tsum);
         }
       return maxi;
    }
};