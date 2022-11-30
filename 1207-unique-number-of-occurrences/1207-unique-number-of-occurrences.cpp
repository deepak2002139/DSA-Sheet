class Solution {
public:
    bool uniqueOccurrences(vector<int>& nums) {
        unordered_map<int,int> mp ;
        int i , n = nums.size() ;
        for(i=0;i<n;i++){
            mp[nums[i]] ++ ;
        }
        vector<int> v ;
        
        for(auto it:mp){
            v.push_back(it.second) ;
        }
        int size = v.size() ;
        sort(v.begin(),v.end()) ;
        for(i=0;i<size;i++){
            cout<<v[i] <<" " ;
        }
        
        int j = 1 ;
        i = 0 ;
        while(j<size){
            if(v[i]==v[j]){
                return false;
            }
            i++ ;
            j++ ;
        }
        
        return true ;
    }
};