class Solution 
{
public:
    string intToRoman(int n) 
    {
        if(n==0) return "";
        if(n>=1000) 
            return "M" + intToRoman(n-1000);
        if(n>=900)
            return "CM" + intToRoman(n-900);
        if(n>=500)
            return "D" + intToRoman(n-500);
        if(n>=400)
            return "CD" + intToRoman(n-400);
        if(n>=100)
            return "C" + intToRoman(n-100);
        if(n>=90)
            return "XC" + intToRoman(n-90);
        if(n>=50)
            return "L" + intToRoman(n-50);
        if(n>=40)
            return "XL" + intToRoman(n-40);
        if(n>=10)
            return "X" + intToRoman(n-10);
        if(n>=9)
            return "IX" + intToRoman(n-9);
        if(n>=5)
            return "V" + intToRoman(n-5);
        if(n>=4)
            return "IV" + intToRoman(n-4);
        if(n>=1)
            return "I" + intToRoman(n-1);
        
        return "_";
    }
};