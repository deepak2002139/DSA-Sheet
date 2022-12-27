class Solution {
public:
    int maxArea(vector<int> height) {
        int n = height.size(); // Size of given array
        
        // Storing {height, index} in vector pair 
        vector<pair<int,int>> prs;
        for(int i=0;i<n;i++){
            prs.push_back({height[i],i});
        }
        
        // Sorted given vector according to height without losing index
        sort(prs.begin(), prs.end()); 
        // Reversing for decending order (max height -->> min height)
        reverse(prs.begin(), prs.end());
        
        int mn = INT_MAX; // For left most point
        int mx = INT_MIN; // For right most point
        int ans = 0;      // MaxArea initialzed to 0
        
        for(auto p: prs){       // Iterating in vector pair
            int h = p.first;    // Current Height
            int i = p.second;   // Current Index
            mn = min(mn,i);     // Minimizing left most point 
            mx = max(mx,i);     // Maximizing right most point
            int val = (mx-mn)*h;// Maximum Area using current Height
            ans = max(ans,val); // Maximizing AnswerArea
        }
        return ans;
    }
};