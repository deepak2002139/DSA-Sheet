class MyCalendar {
public:
    
    // Container that will store the starting point and ending point of the intervals //
    
    vector<pair<int,int>>v;
    
    MyCalendar() {
        v.clear();
    }
    
    bool book(int start, int end) {
        
        // Compare with other intervals //
        
        for(int i=0;i<v.size();i++){
            if(start < v[i].second && end > v[i].first){
                return false;
            }
        }
        
        v.push_back({start,end});
        
        return true;
        
    }
};