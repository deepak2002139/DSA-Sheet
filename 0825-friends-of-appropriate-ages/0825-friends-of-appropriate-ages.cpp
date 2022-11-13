class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        int* temp = new int[122]{0};
        for (int i = 0;i <  ages.size();i++)
        {
            temp[ages[i]]++;
        }
        
        for (int i = 1;i < 122;i++)
        {
            temp[i] = temp[i] + temp[i - 1];
        }
        
        int res = 0;
        for (int i = 0;i < ages.size(); i++)
        {
            if (ages[i] > 14)
                res += (temp[ages[i]] - temp[(int)(0.5*ages[i]) + 7]) - 1;
        }
        
        return res;
    }
};