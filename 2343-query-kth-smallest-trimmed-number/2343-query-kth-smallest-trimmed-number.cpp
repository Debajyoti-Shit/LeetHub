class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        vector<int> ans;
        int size = nums[0].size();
        for(int i=0;i<queries.size();i++){
            int trim = queries[i][1];
            int k = queries[i][0];
            vector<pair<string,int>> s;
            for(int j=0;j<nums.size();j++){
                string sub = nums[j].substr(size-trim);
                s.push_back(make_pair(sub,j));
            }
            
            sort(s.begin(),s.end());
            ans.push_back(s[k-1].second);
            
        }
        return ans;
    }
};