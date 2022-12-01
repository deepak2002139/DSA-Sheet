class Solution {
public:

    bool isVowel(char s)
    {
   return( s == 'a' || s== 'e' || s== 'i' || s== 'o' || s == 'u' || s=='A'||s=='E'||s=='I'||s=='O'||      s=='U')  ;
 }
    bool halvesAreAlike(string s)
    {
        int n = s.size();
        int i = 0;
        int j = n-1;
        int count1 = 0;
        int count2 = 0; 
        while(i<j){
            if(isVowel(s[i]))
            {
                count1++;   
            }
            if(isVowel(s[j]))
            {
                count2++;  
            }
            i++;
            j--;         
        }

        if(count1 == count2) return true;
        return false;
    }
};