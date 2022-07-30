class Solution {
public:
    vector<int>countFreq(string& word){
        vector<int> freq(26);
        for(auto& ch : word)
            freq[ch-'a']++;
        return freq;
    }
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
        vector<string>ans;
        vector<int>Maxfreq(26);//maintains minimum freq of each char required for a word to be universal word

        for(auto& word : B ){
            vector<int>freq= countFreq(word);
            for(int i=0;i<26; i++)
                Maxfreq[i]=max(Maxfreq[i], freq[i]);
        }
        for(auto& word : A){
            vector<int> freq=countFreq(word);
            int i;
            for(i=0;i<26;i++)
                if(freq[i] < Maxfreq[i]) break;
            if(i==26)ans.push_back(word);
        }
        return ans;
    }
};