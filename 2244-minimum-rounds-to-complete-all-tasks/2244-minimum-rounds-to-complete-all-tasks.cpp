class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        int n = tasks.size();
        unordered_map<int,int> mp;
        for(int i =0 ;i < n;i++)
        {
            mp[tasks[i]]++;
        }
        int ans =0;
        for(auto it : mp)
        {
            if(it.second > 0)
            {
                int val = it.second;
                if(val == 1)
                    return -1;
                else if(val % 3 == 0)
                    ans += val/3;
                else if(val % 3 ==1)
                {
                    int div = val/3 -1;
                    ans += div + (val - (3 * div))/2;
                }
                else
                {
                    ans += val /3 +1;
                }
            }
        }
        return ans;
    }
};