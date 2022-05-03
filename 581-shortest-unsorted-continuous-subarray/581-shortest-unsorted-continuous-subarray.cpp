class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int start=-1,end=nums.size();
        int currMax=INT_MIN;
        int currMin=INT_MAX;
        // Iterate from the end, and check weather the element at index "i" is the current minimum element or not. If not then "i" is the starting index.
        for(int i=nums.size()-1;i>=0;i--){
            if(currMin > nums[i]) currMin=nums[i];
            if(nums[i] > currMin ) start=i;
        }
        // Iterate from the start, and check weather the element at index "i" is the current maximum element or not. If not then "i" is the ending index.
        for(int i=0;i<nums.size();i++){
            if(currMax < nums[i]) currMax=nums[i];
            if(nums[i] < currMax) end=i;
        }
        
        if(start==-1) return 0;
        else return end-start+1;
    }
};