class Solution {
private:
  static  bool cmp(pair<pair<int,int>,int>& a,pair<pair<int,int>,int>& b){
        return a.first.second<b.first.second; //sort acco. to end time 
    }
    
    int checkoverlapping(vector<pair<pair<int,int>,int>>& v,int index)
    {
        int idx = -1,low=0,high=index-1;
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            if(v[mid].first.second<=v[index].first.first)
            {
                idx = mid;
                low = mid+1;
            }
            else high=mid-1;
        }
        return idx;
    }
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<pair<pair<int,int>,int>> v(n);
        for(int i=0;i<n;i++){
            v[i].first.first = startTime[i];
            v[i].first.second = endTime[i];
            v[i].second = profit[i];
        }
        sort(v.begin(),v.end(),cmp);
        vector<int> dp(n+1,0);
        dp[0] = v[0].second;
        for(int i=1;i<n;i++){
            int take = v[i].second;
            int idx = checkoverlapping(v,i); // finding the previous non - overlapping index 
			//if exist then include in  take part
            if(idx!=-1)take+= dp[idx];
            dp[i] = max(take,dp[i-1]); // nontake = dp[i-1]
        }
        return dp[n-1];
    }
};