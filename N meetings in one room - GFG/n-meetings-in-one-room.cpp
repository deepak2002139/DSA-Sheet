//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    static bool compare(pair<int,int>&a, pair<int,int>&b)
    {
        return a.second<b.second;
    }
    int maxMeetings(int start[], int end[], int n)
    {
        vector<pair<int ,int >>res;
    for(int i=0;i<n;i++)
    {
        res.push_back({start[i],end[i]});
    }
    sort(res.begin(),res.end(),compare);
    int count=1; 
    pair<int,int> pi={res[0].first,res[0].second};
    for(int i=1;i<res.size();i++)
    {
        if(res[i].first>pi.second)
        {
            pi={res[i].first,res[i].second};
            count++;
        }
    }
    return count;
        // Your code here
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends