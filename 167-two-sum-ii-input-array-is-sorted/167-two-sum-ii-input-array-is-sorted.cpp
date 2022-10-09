class Solution 
{
    // map<int,int> mp;
    // bool ans = false;
public:
    vector<int> twoSum(vector<int>& numbers, int target)
    {
        vector<int> vec;
        int n = numbers.size();
        if(n<=1)
            return vec;
        int i=0;
        int j=n-1;
        for(int i=0;i<j;)
        {
            if(target==numbers[i]+numbers[j])
            {
                vec.push_back(i+1);
                vec.push_back(j+1);
                return vec;
            }
            else if(numbers[i]+numbers[j]<target)
                i++;
            else
                j--;
        }
        return vec;
    }
};