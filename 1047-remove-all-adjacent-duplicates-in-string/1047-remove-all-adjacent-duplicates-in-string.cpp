class Solution 
{
public:
    bool check(char a, char b)
    {
        return a==b;
    }
    string removeDuplicates(string S)
    {
        for (int i=1; i<S.size(); i++)
        {
			if (S[i] == S[i-1]){
				S.erase(i-1,2);
				i = max(0,i-2);
			}
        }
        return S;
    }
};