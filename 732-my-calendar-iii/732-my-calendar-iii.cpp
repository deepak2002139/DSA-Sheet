class MyCalendarThree 
{
    map<pair<int,int>,int >map1 ;
public:
    MyCalendarThree() 
    {
        map1=map<pair<int,int>,int>(); 
        
    }
    
    int book(int start, int end) 
    {
        map<pair <int , int >, int >map2;
        int res =1;
        for(const auto& p : map1)
        {
            int newStart =max(start, p.first.first);
            int newEnd = min(end, p.first.second);
            if(newStart< newEnd)
            {
                map2[{newStart,newEnd}]= max(map2[{newStart, newEnd}],p.second+1);
                res=max(map2[{newStart, newEnd}],res);
            }
            else{
                res=max(res,p.second);
            }                               
        }
        for(const auto& p :map2) 
        {
            map1[p.first] = p.second;
        }
        if (map1.find({start, end}) == map1.end()) 
            map1[{start, end}] = 1;
        return res;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */