class Solution {
public:
int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {

    int mod=1e9+7;
    vector<pair<int,int>> res;
    for(int i=0;i<speed.size();i++){
        res.push_back({efficiency[i],speed[i]});
    }
	
    sort(res.begin(),res.end());
    priority_queue<int,vector<int>,greater<int>> pq;
    long sum=0;
    long ans=0;
    for(int i=n-1;i>=0;i--){
        sum +=res[i].second;
        pq.push(res[i].second);
        
        if(pq.size()>k){
            sum -=pq.top();
            pq.pop();
        }
        ans=max(ans,sum*res[i].first);
    }
    return ans%mod;
}
};