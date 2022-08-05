class Solution {
public:
    int solve(vector<int> &nums, int target, vector<int> &memo){
        if(target == 0) return 1;
        if(target < 0) return 0;
        if(memo[target] != -1) return memo[target];
        int ans=0;
        for(auto &num : nums){
            ans+=solve(nums, target-num, memo);
        }
        return memo[target]=ans;
    }
    int combinationSum4(vector<int>& nums, int target) {
        vector<int>memo(target+1,-1);
        return solve(nums,target,memo);
    }
};