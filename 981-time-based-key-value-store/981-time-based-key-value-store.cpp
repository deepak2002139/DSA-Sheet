class TimeMap 
{
    unordered_map<string, vector<pair<int , string>>>map ;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) 
    {
        map[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp)
    {
        if(map.find(key)==map.end())
            return "";
        int l =0;
        int r = map[key].size()-1;
        if(map[key][0].first>timestamp)
            return "";
        string ans ;
        while (l<=r)
        {
            int mid =l+(r-l)/2;
            if(map[key][mid].first==timestamp)
                return map[key][mid].second;
            else if(map[key][mid].first<timestamp)
            {
                ans = map[key][mid].second;
                l = mid+1;
            }
            else
                r= mid-1;
        }
        return ans;
    }
    
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */