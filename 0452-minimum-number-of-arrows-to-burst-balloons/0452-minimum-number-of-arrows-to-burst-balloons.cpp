bool com (vector<int>& l, vector<int>& r) {
    return l[0] < r[0];
}
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        std::sort(points.begin(), points.end(), com);
        int i = 0;
        int len = points.size();
        int cxs, cxe, dxs, dxe;
        int res = 0;
        while (i < len) {
            cxs = points[i][0];
            cxe = points[i][1];
            i++;
            while (i < len) {
                dxs = points[i][0];
                dxe = points[i][1];
                if (cxe >= dxs && dxe >= cxs) {
                    cxs = max(cxs, dxs);
                    cxe = min(cxe, dxe);
                    i++;
                }
                else {
                    break;
                }
            }
            res++;
        }
        return res;
    }
};