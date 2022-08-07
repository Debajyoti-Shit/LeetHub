class Solution {
public:
    int count(vector<int>& nums, int num){
        int c=0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]>=num)
                c++;
        }
        return c;
    }
    int specialArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int start = 0; 
        int end = nums.size();
        while(start<=end){
            int mid = start+ (end-start)/2;
            int c = count(nums, mid);
            if(c==mid)
                return mid;
            else if(c>mid)
                start=mid+1;
            else
                end=mid-1;
        }
        return -1;
    }
};