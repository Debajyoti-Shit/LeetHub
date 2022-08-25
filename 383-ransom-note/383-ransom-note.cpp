class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int n=ransomNote.size();
        int m=magazine.size();
        if(n>m)return false;
        int x[26]={0};
        for(int i=0;i<m;i++) x[magazine[i]-'a']++;
        for(int i=0;i<n;i++) x[ransomNote[i]-'a']--;
        for(int i=0;i<26;i++) if(x[i]<0) return false;
        
        return true;
    }
};