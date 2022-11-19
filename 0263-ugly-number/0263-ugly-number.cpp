class Solution {
public:
    bool isUgly(int n) {
        if(n<=0)
          return 0;
        if(n<=5 )
          return 1;
        int i;
        for(i=2;i<=5;i++)
        {
            if(n<=5 )
              return 1;
            if(n%i==0)
            {
              n=n/i;
              i=i-1;
            }  
        }
        return 0;
    }
};