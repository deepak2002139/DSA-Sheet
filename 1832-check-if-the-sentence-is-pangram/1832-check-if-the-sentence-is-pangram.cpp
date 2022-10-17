class Solution 
{
public:
    bool checkIfPangram(string sentence)
    {
        vector<bool>isCharAvailable(26, false);
        for(char &letter: sentence)
        {
            isCharAvailable[letter-'a']=true;
        }
        
        for(int i=0;i<26;i++) 
        {
            if(!isCharAvailable[i]) 
            {
                return false;
            }
        }
        return true;
    }
};