// class Solution
// {
//     public:
//         bool check(string s)
//         {
//             int k = s.size();
//             int val = stoi(s);
//             if (val > 255 || val < 0)
//                 return false;
//             if (k < log10(val) + 1)
//                 return false;
//             return true;
//         }
//     string generate(string s, int n, int i, int j, int k)
//     {
//         string s1 = s.substr(0, i + 1);
//         string s2 = s.substr(i + 1, j - i);
//         string s3 = s.substr(j + 1, k - j);
//         string s4 = s.substr(k + 1, n - 1 - k);
//         if (check(s1) && check(s2) && check(s3) && check(s4))
//             return s1 + "." + s2 + "." + s3 + "." + s4;
//         return "";
//     }
//     vector<string> restoreIpAddresses(string s)
//     {
//         vector<string> ans;
//         int n = s.size();
//         for (int i = 0; i < n; i++)
//         {
//             for (int j = i + 1; j < n; j++)
//             {
//                 for (int k = j + 1; k < n; k++)
//                 {
//                     string temp = generate(s, n, i, j, k);
//                     if (temp.length() > 0)
//                         ans.push_back(temp);
//                 }
//             }
//         }

//         return ans;
//     }
// };
class Solution {
public:
   vector<string>ans;
void back(string &s, string temp, int idx, int dig_cnt){
if(dig_cnt>4) return;
if(dig_cnt==4 && idx >=s.length()){
temp.pop_back();
ans.push_back(temp);
return;

}

for(int i = 1; i<=3 &&idx+i<=s.length(); i++){

string num = s.substr(idx,i);
if(num[0]=='0' && i!=1) break;
else if(stol(num)<=255){
back(s,temp+s.substr(idx,i)+ ".", idx+i, dig_cnt+1);
}
}
}

vector<string> restoreIpAddresses(string s){
back(s,"",0,0);
return ans;

}

};