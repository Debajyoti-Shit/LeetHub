class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length()) return false;
        unordered_map<char,int>mp;
        for(int it=0;it<s.size();it++){
            mp[s[it]]++;
            mp[t[it]]--;
        }
        for(auto it: mp){
            if(it.second!=0) return false;
        }
        return true;
    }
};