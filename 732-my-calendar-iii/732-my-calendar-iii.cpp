class MyCalendarThree {
    map<int, int> mp;
public:
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
        
        mp[start]++, mp[end]--;
        int ans = 0, curr = 0;
        
        for(auto &i : mp)
            curr += i.second, ans = max(ans, curr);
        
        return ans;
    }
};