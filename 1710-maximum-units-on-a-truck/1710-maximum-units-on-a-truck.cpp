class Solution {
public:
    static bool compare(vector<int>a , vector<int>b)
    {
        return a[1]> b[1];
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) 
    {
        int res =0;
        sort(boxTypes.begin(), boxTypes.end(),compare)  ; 
         for (const vector<int>& v : boxTypes)
         {
            res += min(truckSize, v[0]) * v[1];
            truckSize -= min(truckSize, v[0]);
            if (truckSize == 0)
                return res;
        } 
        return res;
    }
};