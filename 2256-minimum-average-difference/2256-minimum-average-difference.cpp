class Solution 
{
public:
    int minimumAverageDifference(vector<int>& nums)
    {
        int n=nums.size();
        long long int sec=0;
        for(int i=0;i<n;i++)
            sec+=nums[i];
        long long int first=0;
        int ans=INT_MAX, ind=-1;
        for(int i=0;i<n;i++){
            first+=nums[i];
            sec-=nums[i];
            int tmp=0;
            if(n-1-i > 0)
                tmp=abs(first/(i+1) - (sec/(n-1-i)));
            else
                tmp=abs(first/(i+1));  
            if(tmp < ans && i>ind){
                ind=i;
                ans=tmp;
            }
        }
        return ind;
    }
};