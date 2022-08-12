class Solution {
public:
    int findMin(vector<int>& nums) {
        int mn=nums[0];
        int lo=0,hi=nums.size()-1;
        while(lo<=hi){
            int mid = lo + (hi-lo)/2;
            if(nums[mid] < mn){ 
                mn= nums[mid];
                hi=mid-1;
            }else lo = mid + 1;
            
        }
        return mn;
    }
};