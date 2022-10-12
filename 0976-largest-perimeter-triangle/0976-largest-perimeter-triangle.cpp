// class Solution {
// public:
//     int largestPerimeter(vector<int>& nums) 
//     {
//         sort(nums.begin(), nums.end());
//         int n = nums .size();
//         // if(nums[n-3]+nums[n-2]<=nums[n-1])
//         //     return 0;
//         int max=0;
//         int i=n-3;
//         while(i--)
//         { 
//          if (nums[i-3]+nums[i-2]<=nums[i-1])
//             continue;
//         else return nums[i-3]+nums[i-2]+nums[i-1];   
//         }
//         return 0;
//     }
// };
class Solution {
public:
int largestPerimeter(vector<int>& nums) 
{
        sort(nums.begin(), nums.end());
        for(int i=nums.size()-1; i>=2; i--)
            if(nums[i]< nums[i-1]+nums[i-2]) 
                return nums[i]+nums[i-1]+nums[i-2];
        return 0;
}
};