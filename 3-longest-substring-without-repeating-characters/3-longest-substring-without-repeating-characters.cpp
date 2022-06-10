class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		unordered_set<char> set;
		int i = 0, j = 0, n = s.size(), ans = 0;
    
		while( i<n && j<n){
			if(set.find(s[j]) == set.end()){ //If the character does not in the set
				set.insert(s[j++]); //Insert the character in set and update the j counter
				ans = max(ans, j-i); //Check if the new distance is longer than the current answer
			}
			else{
				set.erase(s[i++]); 
				/*If character does exist in the set, ie. it is a repeated character, 
				we update the left side counter i, and continue with the checking for substring. */
			}
		}
		return ans;
	}
};



// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
//         vector<int>mpp(256,-1);
//         int left=0;int right=0;
//         int n=s.size();
//         int len=0;
//         while(right<n){
//             if(mpp[s[right]]!=-1){
//                 left=max(mpp[s[right]]+1,left);
//             }
//             mpp[s[right]]=right;
//             len=max(len,right-left+1);
//             right++;
//         }
//         return len;
//     }
// };