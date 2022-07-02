class Solution {
    const long int MOD=1e9+7;
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        horizontalCuts.push_back(h);
        verticalCuts.push_back(w);
        
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        
        long int ans = 0, maxWidth = 0, maxHeight = 0;

        for (int i = 0, prev = 0; i < horizontalCuts.size(); i++) {
            maxHeight = max(maxHeight, (long int) horizontalCuts[i] - prev);
            prev = horizontalCuts[i];
        }
        
        for (int i = 0, prev = 0; i < verticalCuts.size(); i++) {
            maxWidth = max(maxWidth, (long int) verticalCuts[i] - prev);
            prev = verticalCuts[i];
        }
        ans= maxHeight * maxWidth;
        return ans % MOD;
        
    }
};