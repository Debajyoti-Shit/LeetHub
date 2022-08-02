class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int lo=0,hi=arr.size()-1;
        int mid= lo + (hi-lo)/2;
        while(lo<hi){
            
            if(arr[mid] < arr[mid+1]) lo=mid+1;
            else hi=mid;
            mid= lo + (hi-lo)/2;
        }
        return lo;
    }
};
/*
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        for(int i=1;i<arr.size();i++){
            if(arr[i] < arr[i-1]) return i-1;
        }
        return -1;
    }
};
*/