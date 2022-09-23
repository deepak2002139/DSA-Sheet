class Solution
{
    public int concatenatedBinary(int n) 
    {
        long variable=0,i=0;
        while(i++<n)
            variable= ((variable<<(1+(int)(Math.log(i)/Math.log(2))))+i)%1000000007;
        return (int)variable;
    }
}