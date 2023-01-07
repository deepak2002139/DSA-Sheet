// class Solution {
// public:
//     int canCompleteCircuit(vector<int>& gas, vector<int>& cost) 
//     {
//         int ans=0;
//         int n =gas.size();
//         int tank=0;
//         int used=0;
//         for(int i =0;i<n ;i++)
//         {
//             tank=gas[i];
//             used=cost[i];
//             int j=i+1;
//             while(!j==(i-1))
//             {
//                 if(used>tank)
//                 {
//                     break;
//                 }
//                 tank+=gas[j];
//                 used+=cost[i];
//                 if(j==n-1)
//                     j=0;
//             }
//             if(tank+used==0)
//                 ans=i;
//         }
//             return ans ;
        
//     }
// };
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size(),totalcost=0,totalfuel=0;
        int curr_fuel=0,start=0;
        for(int i=0;i<n;i++)
        {
            totalcost+=cost[i];
            totalfuel+=gas[i];
            curr_fuel+=gas[i]-cost[i];
            if(curr_fuel<0)
            {
                start=i+1;
                curr_fuel=0;
            }
        }
        if(totalcost>totalfuel) return -1;
        return start;
    }
};