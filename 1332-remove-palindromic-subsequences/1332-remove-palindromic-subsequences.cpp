class Solution {
public:
    bool isPalindrom(string s){
        int l=0,h=s.size()-1;
        while(l<h){
            if(s[l]!=s[h]) return false;
            l++;h--;
        }
        return true;
    }
    int removePalindromeSub(string s) {
        if(s.size()==0) return 0;
        else if(isPalindrom(s)) return 1;
        else return 2;
    }
};