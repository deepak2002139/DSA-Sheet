// class Solution {
// public:
//     // bool cmp(vector<int>&a, vector<int>&b)
//     // {
//     //     return a[0]<b[0];
//     // }
// //     void solve(int x1,int x2,int y1,int y2,vector<veector<int>>&points)
// //     {
        
// //     }
//     int maxPoints(vector<vector<int>>& points) 
//     {
//       // sort(points.begin(),points.end(),cmp)  
//           // for line to be same slope and the constant should should should be same
//           map<pair<double,double>,int>mp;
//           int ans=0;
//         int n= points.size();
//         for(int i=0;i<n;i++)
//         {
//             for(int j=i+1;j<n;j++)
//             {
//                 if((points[j][0]-points[i][0])==0)
//                 {
//                   double m=10e4;
//                   double c=10e4;
//                     mp[{m,c}]++;
//                     continue;
//                 } 
//                 double m=(points[j][1]-points[i][1])/(points[j][0]-points[i][0]);
//                 int c=points[i][1]-m*points[i][0];
//                 mp[{m,c}]++;
//             }
//         }
//         for(auto it :mp)
//             ans=max(ans,it.second);
//         return ans;
//     }
// };
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        if(points.size() == 1)return 1;
        int maxi=2; /* as minimum number points needed to make
                    a line is 2 */
        for(int i=0;i<points.size();i++){
            unordered_map<float,int> m;
            for(int j=0;j<points.size();j++){
                if(i != j){
                    int y = points[j][1] - points[i][1];
                    int x = points[j][0] - points[i][0];
                    if(x == 0){
                        auto it = m.find(1e9);
                        if(it != m.end()){
                            maxi = max(maxi, it->second + 2);
                            it->second+=1;
                        }else m[1e9]++;
                    }else{
                        float slope = (float)y/x;
                        auto it = m.find(slope);
                        if(it != m.end()){
                            maxi = max(maxi, it->second + 2);
                            it->second+=1;
                        }else m[slope]++;
                    }
                }
            }
        }
        return maxi;
    }
};