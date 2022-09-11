class Solution {
    public int maxSubarraySumCircular(int[] nums) 
    {
        int n=nums.length;
      return Integer.max(kadane(nums,n), reverseKadane(nums,n));
   }
   static int kadane(int arr[],int n){
       int max = arr[0];
       int res = arr[0];
       for(int i =1;i<n;i++){
           max = Math.max(max+arr[i],arr[i]);
           res = Math.max(max,res);
       }
       return res;
   }
   static int reverseKadane(int arr[],int n)
   {
       int max_kadane = kadane(arr,n);
       if(max_kadane<0){
           return max_kadane;
       }
       int sum = 0;
       for(int i = 0;i<n;i++){
           sum+=arr[i];
           arr[i]=-arr[i];
       }
       int max_cir = sum+kadane(arr,n);
       return max_cir;
   }
}