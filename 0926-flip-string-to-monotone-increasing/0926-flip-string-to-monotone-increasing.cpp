class Solution
{
    public:
        int minFlipsMonoIncr(string s)
        {
            int one = 0, zero = 0;
            for (int k = 0; k < s.length(); k++)
            {
                if (s[k] == '1')
                {
                    one = min(zero, one);
                    zero++;
                }
                else one++;
            }
            return min(one, zero);
        }
};