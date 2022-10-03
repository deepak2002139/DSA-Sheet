// class Solution {
// public:
//     int minCost(string colors, vector<int>& neededTime) 
//     {
//         int time=0;
//         int n=colors.size();
//         if(n==1)
//             return time;
//         for(int i=0;i<n-1;i++)
//         {
//             if(colors[i]==colors[i+1])
//             {
//                 if(neededTime[i]<neededTime[i+1])
//                     time+=neededTime[i];
//                 else
//                     time+=neededTime[i+1];
//             }
//             else continue;
//         }
        
//         return time;
//     }
// };
class Solution {
public:
    int minCost(string c, vector<int>& nT) {
        int ans=0,n=c.size();
        pair<char,int> prev={c[0],nT[0]};
        for(int i=1;i<=n-1;i++){
            if(c[i]==prev.first){
                if(nT[i]<prev.second){
                    ans+=nT[i];
                }else{
                    ans+=prev.second;
                    prev={c[i],nT[i]};
                }
            }else{
                prev={c[i],nT[i]};
            }
        }
        return ans;
        
    }
};