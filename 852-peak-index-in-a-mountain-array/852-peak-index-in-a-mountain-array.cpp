class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        for(int i=1;i<arr.size();i++){
            if(arr[i] < arr[i-1]) return i-1;
        }
        return -1;
    }
};