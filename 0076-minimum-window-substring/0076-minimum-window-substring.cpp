// class Solution {
// public:
//     string minWindow(string s, string t)
//     {
//         int n= s.length
//         string ans = "";
//         unordered_map<char, int > map1,map2;
//         for(auto it :t)
//             map2[it]++;
//         itn i =0;j=0;
//         while(i<m)
//         {
//             map1[s[i]]++;
//             while(j<=i && map1[s[j]]>map2[s[j]])
//             {
//                 map1[s[j]]--;
//                 j++;
//             }
//             if(map2[s[i]])
//             {
                
//             }
//         }
//     }
// };
class Solution {
public:
    string minWindow(string s, string t) {
        int m=s.size(),n=t.size(),start=-1,end=0;
        unordered_map<char,int>mp1,mp2;  //mp1->s , mp2->t
        if(m<n)return "";
        for(auto it:t)mp2[it]++;
        
        int i=0,j=0;
        while(i<m){
            // expand the window
            mp1[s[i]]++;  
            //contract the window
            while(j<=i && mp1[s[j]]>mp2[s[j]])
            {
                mp1[s[j]]--;
                j++;
            }
        // if the crrent s[i] is present in t, then only check 
        // for all char of 't' present in s and minimize the size
        // bcz if s[i] is not present in t ,then t's character
        // count hasn't changed in s from backward side
        
            if(mp2[s[i]]){
                //check all characters of 't' present in the window
                int is_available=1;
                for(auto it : mp2){
                    if(mp1[it.first]<it.second){
                        is_available=0;
                        break;
                    }
                }
                if(is_available==1){
                    if(start==-1 || end-start+1>i-j+1){
                        start=j;
                        end=i;
                    }
                }
            }
            i++;
        }
        return start==-1 ? "" : s.substr(start,end-start+1);
    }
};