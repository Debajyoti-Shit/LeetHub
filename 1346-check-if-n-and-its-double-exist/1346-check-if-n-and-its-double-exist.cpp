class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set<int>us;
        
        for(int i = 0; i<arr.size(); i++){
		//if the double of the element existed previously in the array
            if(us.find(arr[i]*2) != us.end()){
                return true;
            }
			
       //as the array is of integers so no need to check for the half of odd numbers
	   //here we have checked if the number is even if yess ...then check if there is half of the current number present previously in the array
            if(arr[i]%2 == 0){
                if(us.find(arr[i]/2) != us.end()){
                    return true;
                }
            }
          //if none of the above cases are true then we will insert the current element into the unordered set and will move further checking other elements
            us.insert(arr[i]);
        }
        
        return false;
    }
};