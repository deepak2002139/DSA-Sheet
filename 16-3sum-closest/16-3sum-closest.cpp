class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) 
    {
        int mini= INT_MAX;
        int ans =0;
        int n = nums.size();
        sort(nums.begin(), nums.end());
          for(int i=0; i<n-2; i++) // pointer 1 pointing 0th index
        {
            int j=i+1; // pointer 2 pointing 1st index
            int k=n-1; // pointer 3 last index
            while(j<k)
            {
                int sum=nums[i]+nums[j]+nums[k]; // current sum of elements at each pointer in nums
                if(abs(sum-target)<mini) // if difference of current sum and target is minimum than previous sum store it in ans
                {
                    mini = abs(sum-target);
                    ans=sum;
                }
                if(sum<target) //if current sum is less than required target  move poniter 2 towards right
                    j++;
                else // if current sum is greater than required target  move poniter 3 towards left
                    k--;
            }
        }
        return ans;      
    }
};