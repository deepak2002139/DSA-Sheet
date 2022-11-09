class StockSpanner 
{
public:
    stack<pair <int , int>> st ;
    int  c=0;
    StockSpanner() 
    {
        c=0;
    }
    
    int next(int price)
    {
        c+=1;
        while(!st.empty()&& price>=st.top().first)
        {
            st.pop();
        }
        int span=0;
        if(st.empty())
            span =c;
        else 
            span = c- st.top().second;
        st.push({price, c});
        
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */