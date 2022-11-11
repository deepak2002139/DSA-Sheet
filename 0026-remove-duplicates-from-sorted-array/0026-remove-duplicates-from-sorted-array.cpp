class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int p,u=0;
        for (int i=0;i<size(nums);i++){
            p=0;
            for (int j=(i+1);j<size(nums);j++){
                if(nums[i]==nums[j]){
                    p++;
                    break;
                }
            }
            if (p==0){
                nums[u]=nums[i];
                u++;
            }
        }
        return u;}
};