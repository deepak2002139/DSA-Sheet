class Solution 
{
//     brute force algorithm 
public:
//     int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
//         int n = img1.size();
//         int cnt[60][60]={0};
//         int ans = 0;
//         for(int i = 0;i<n;i++)
//             for(int j = 0;j<n;j++){
//                 if(img1[i][j]==0) continue;
//                 for(int I = 0;I<n;I++){
//                     for(int J = 0;J<n;J++){
//                         if(img2[I][J]==0) continue;
//                         ans = max(ans,++cnt[n+i-I][n+j-J]);
//                     }
//                 }
//             }

//         return ans;
//     
//     
//     using map this soluion is been solved 
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        int cnt[60][60]={0};
        int ans = 0;
        for(int i = 0;i<n;i++)
            for(int j = 0;j<n;j++){
                if(img1[i][j]==0) continue;
                for(int I = 0;I<n;I++){
                    for(int J = 0;J<n;J++){
                        if(img2[I][J]==0) continue;
                        ans = max(ans,++cnt[n+i-I][n+j-J]);
                    }
                }
            }

        return ans;
    }
    
};