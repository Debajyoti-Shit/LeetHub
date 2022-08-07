class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>v;
        int lo=0,hi=nums.size()-1;
        while(lo<=hi){
            if(nums[lo]+nums[hi] == target){
                v.push_back(lo+1);
                v.push_back(hi+1);
                return v;
            }
            else if((nums[lo]+nums[hi]) > target) hi--;
            else if((nums[lo]+nums[hi]) < target) lo++;
        }
        return v;
    }
};