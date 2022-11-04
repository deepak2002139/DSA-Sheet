class Solution
{
public:
    bool sol(char ch)
   {
       return{
           ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'||ch=='A'||ch=='E'||ch=='I'||ch=='O'||ch=='U'
       };
   }
    string reverseVowels(string s)
    {
        // int n = s.size();
        vector<char>v1;
        for(auto it:s)
        {
            if(sol(it))
            {
                v1.push_back(it);
            }
        }
        reverse(v1.begin(),v1.end());
        int j=0;
        for(int i=0;i<s.size();i++)
        {
            if(sol(s[i]))
            {
                s[i]=v1[j];
                j++;
            }
        }
        return s;
    }
};


// class Solution {
// public:
//     bool sol(char ch)
//     {
//         return {
//             ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'||ch=='A'||ch=='E'||ch=='I'||ch=='O'||ch=='U'
//         };
//     }
//     string reverseVowels(string s) {
//         vector<char> vow;
//         for(auto i:s)
//         {
//             if(sol(i))
//             {
//                 vow.push_back(i);

//             }
//         }
//         reverse(vow.begin(),vow.end());
//         int k=0;
//         for(int i=0;i<s.size();i++)
//         {
//             if(sol(s[i])
//             {
//                 s[i]=vow[k];
//                 k++;
//             }
//         }
//         return s;
//     }
// // };