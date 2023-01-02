class Solution
{
public:
    bool detectCapitalUse(string word) 
    {
        // int countu=0;
        // bool flag=false;
        // int n=word.size();
        // for(int i=1;i<n;i++)
        // {
        //     if(isupper(word[i]))
        //     {
        //         countu++;
        //     }
        // }
        // if(word[0]>=65 && word[0]<=90 )
        //     flag=true;
        // // for(int i=1;i<n;i++)
        // // {
        // //     if(word[i]<='Z' && word[i]>='A')
        // //     {
        // //         flag3=true;
        // //     }
        // //     else false;
        // // }
        // return countu==n||(countu==1&&flag)||(countu==0);
        
 int cap=0 ,sml= 0;
    int n = word.size();
    for(int i =0 ; i < n ; i ++){
        char code  =word[i];
        if     (code >= 65 && code <= 90 )cap++;
        else if(code >= 97 && code <= 122)sml++;
    }
    return cap == n|| sml == n|| (cap == 1 && word[0] >= 65 && word[0] <= 90);
    }
};