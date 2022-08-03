class Solution {
public:
    int findTheDistanceValue(vector<int>& a1, vector<int>& a2, int d) {
        
        int count=0;
            for(int i=0;i<a1.size();i++){
                int k=0;
                for(int j=0;j<a2.size();j++){
                    if(abs(a1[i]-a2[j])<=d) k=1;
                    
                }
                if(k==0) count++;
            }
        return count;
    }

};