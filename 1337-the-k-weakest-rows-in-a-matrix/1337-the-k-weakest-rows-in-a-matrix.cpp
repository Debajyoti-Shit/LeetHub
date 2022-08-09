class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int rows = mat.size(), cols = mat[0].size();
        vector<int> ans(k,1);
        multimap<int, int> m;
        for(int i = 0; i < rows; i++) {
            int ind = lower_bound(mat[i].rbegin(), mat[i].rend(), 1) - mat[i].rbegin();
            cout << cols - ind << endl;
            m.insert({cols - ind, i});
        }
        int j = 0;
        for(auto i : m){
            if(j == k) break;
            ans[j] = i.second;
            j++;
        } 
        
        return ans;
    }
};