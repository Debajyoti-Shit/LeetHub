class Solution {
public:
    int count(string &s,char c){
        int miss=0;
        for(int i=0;i<s.size();i=i+2){
            if(s[i]!=c) miss++;
        }
        return miss;
    }
    int minSwaps(string s) {
        int cnt0=0,cnt1=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='0') cnt0++;
            else cnt1++;
        }
        if(abs(cnt0-cnt1) > 1) return -1;
        
        if(cnt0 > cnt1) return count(s,'0');
        if(cnt0 < cnt1) return count(s,'1');
        return min(count(s,'0'), count(s,'1'));

    }
};