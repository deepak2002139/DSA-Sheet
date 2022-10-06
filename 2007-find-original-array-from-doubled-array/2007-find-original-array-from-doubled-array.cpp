class Solution
{
public:
    vector<int> findOriginalArray(vector<int>& changed)
    {
        int n=changed.size(),c=0;
        unordered_map<int,int>m;
           vector<int>v;
        if(n%2!=0)
        {
            return v;
        }
     sort(changed.begin(),changed.end());
         for(int i=0;i<n;i++)
         {
             m[changed[i]]++;
         }
        for(int i=0;i<n;i++)
        {
            if(m[2*changed[i]]!=0&&m[changed[i]]!=0)
            {
                   c++;
                v.push_back(changed[i]);
                    m[changed[i]]--;
                  m[2*changed[i]]--;
            }
        }
       // return v;
        for(auto i : m)
        {
            if(i.second != 0)
            {
                return vector<int>();
            }
        }
        return v;
       
    }
};