// class Solution {
// public:
//     vector<vector<int>> merge(vector<vector<int>>& intervals) 
//     {
//         if(intervals.size()<2)
//             return intervals;
//         int i=1;
//         vector<vector<int>> ans;
//         sort(intervals.begin(),intervals.end());
//         ans.push_back(intervals[0]);
//         int n =intervals.size();
//         int m= intervals.size();
//         while(i<intervals.size())
//         {
//             if(intervals[i][0]<=ans.back()[1])
//             {
//                 if(ans.back()[1]<=intervals[i][1])
//                 {
//                     ans.back()[1]=intervals[i][1];
//                 }
//                 else{ans.push_back(intervals[i]);
//                     }
//                 i++;
//             }
//         }
//         return ans;
//     }
// };
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size()<2)
        return intervals;
        int i=1;
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());
        ans.push_back(intervals[0]);
        while(i<intervals.size())
        {
            if(intervals[i][0]<=ans.back()[1]){
                if(ans.back()[1]<=intervals[i][1]){
                    ans.back()[1]=intervals[i][1];
                }
            }
            else{
                ans.push_back(intervals[i]);
            }
            i++;
        }
        return ans;
    }
};