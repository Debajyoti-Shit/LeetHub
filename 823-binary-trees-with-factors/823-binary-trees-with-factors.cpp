class Solution {
public:
    int MOD = 1000000007;
    int numFactoredBinaryTrees(vector<int>& arr) 
    {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        vector<long> dp(n);
        dp[0] = 1;
        int ans = 0;
        for (int idx = 1; idx < n; idx++)
        {
            int target = arr[idx];  //root 
            //===========================================
            //EXACTLY SAME AS CONCEPT OF "TWO SUM" PROBLEM
            
            int i = 0, j = idx - 1; //two pointers for the "Two product" problem (same as Two Sum)
            long ways = 1;
            while(i <= j)
            {
                long prod = (((long)arr[i]) * (arr[j]));
                if (prod == target) 
                {
                    if (i == j) ways += (dp[i] * dp[j]) % MOD;
                    else ways += ((dp[i] * dp[j]) * 2) % MOD;  
                    //"*2" becoz 1) arr[i] is left child, arr[j] is right child
                    //           2) arr[j] is left child, arr[i] is right child
                    
                    i++;
                    j--;
                }
                else if (prod < target) i++;
                else if (prod > target) j--;
            }
            
            //============================================================
            dp[idx] = ways;
            ans  = (int)((ans + dp[idx]) % MOD); //add all the cases
        }
        return ans + 1;
        
        
    }
};