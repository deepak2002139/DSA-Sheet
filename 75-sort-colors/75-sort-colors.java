class Solution 
{
    public void sortColors(int[] nums) 
    {
        int red=0;
        int blue=0;
        int white=0;
        for(int i=0;i<nums.length;i++)
        {
            if(nums[i]==0)
                red++;
            if(nums[i]==1)
                white++;
        }
        blue=nums.length-white-red;
//         now make a new array with the following information 
        int []  arr = new int [nums.length];
        for(int i=0;i<red;i++)
        {
            nums[i]=0;
        }
        for(int i=red;i<white+red;i++)
        {
            nums[i]=1;
        }
        for(int i=red+white;i<nums.length;i++)
        {
            nums[i]=2;
        }
        // return arr;
    }
}