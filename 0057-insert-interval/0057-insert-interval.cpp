class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& ni) {

        //this question just requires a greedy iteration and logic with while loops
        vector<vector<int>>ans;



        int i=0;
        int len=intervals.size();

        //non overlapping intervals before the new intervals
        while(i<len &&intervals[i][1]<ni[0]){
            ans.push_back(intervals[i]);
            i++;
        }
        //now we will merge all the overlapping intervals till now new intervals concides with the previously merged intervals

        while(i<len && intervals[i][0]<=ni[1]){
            //naye wale interval ka start definitely smaller than eqaul to ending of the nw interval 
            //surelythey can be merged togther
            ni[0]=min(intervals[i][0],ni[0]);
            ni[1]=max(intervals[i][1],ni[1]);
            i++;
        }
        ans.push_back(ni);
        while(i<len){
            ans.push_back(intervals[i]);
            i++;
        }
        
        return ans;
    }
};