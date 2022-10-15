// class Solution {
// public:
//     string str;
//     int solve(int i, int prev, int len, int k) {
//         if(k < 0) return 1e9;
//         if(i >= str.size()) return 0;
        
//         int del = solve(i+1, prev, len, k-1);
//         int keep = 0;
//         if(str[i] - 'a' == prev) {
//             if(len == 1 || len == 9 || len == 99) {
//                 keep += 1;
//             }
//             keep = keep + solve(i+1, prev, len+1, k);
//         }
//         else {
//             keep = 1 + solve(i+1, str[i] - 'a', 1, k);
//         }
        
//         return min(del, keep);
//     }
//     int getLengthOfOptimalCompression(string s, int k) {
//         str = s;
//         return solve(0, 26, 0, k);
//     }
// };
// Memoization (Using 4D DP)

int dp[100][27][100][100];
class Solution {
public:
    string str;
    int solve(int i, int prev, int len, int k) {
        if(k < 0) return 1e9;
        if(i >= str.size()) return 0;
        if(dp[i][prev][len][k] != -1) return dp[i][prev][len][k];
            
        int del = solve(i+1, prev, len, k-1);
        int keep = 0;
        if(str[i] - 'a' == prev) {
            if(len == 1 || len == 9 || len == 99) {
                keep += 1;
            }
            keep = keep + solve(i+1, prev, len+1, k);
        }
        else {
            keep = 1 + solve(i+1, str[i] - 'a', 1, k);
        }
        
        return dp[i][prev][len][k] = min(del, keep);
    }
    int getLengthOfOptimalCompression(string s, int k) {
        str = s;
        memset(dp, -1, sizeof(dp));
        return solve(0, 26, 0, k);
    }
};