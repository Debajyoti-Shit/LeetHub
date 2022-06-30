class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int mid= n%2==0 ? n/2 -1: (n+1)/2 -1;
        
        int moves=0;
        for(int i=0;i<nums.size();i++){
            moves+=abs(nums[i]-nums[mid]);
        }
        return moves;
    }
};