// class Solution {
// public:
//     double largestTriangleArea(vector<vector<int>>& points) 
//     {
//         double maxArea=0;
//         double currArea=0;
//         int n = points.size();
//         for(int i =0;i<n ; i++)
//         {
//             for(int j =i+1;j<n;j++)
//             {
//                 for(int k= j+1;j<n;j++)
//                 {
//                     double x1=(double)points[i][0];
//                     double x2=(double)points[j][0];
//                     double x3=(double)points[k][0];
                    
//                     double y1=(double)points[i][1];
//                     double y2=(double)points[j][1];
//                     double y3=(double)points[k][1];
//                     currArea=((double)1/(double)2)*(x1*(y2-y3)+x2*(y3-y1)+x3*(y2-y1));
//                     if(currArea<0)
//                         currArea*-1;
//                     if(currArea>maxArea)
//                         maxArea=currArea;
//                 } 
//             }
//         }
//         return maxArea;
        
//     }
// };\

class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) 
    {
        double res=0;
        for (auto x: points)
        {
            for (auto y: points)
            {
                for (auto z: points)
                {
                   res=max(res,0.5* abs(x[0]*y[1]-x[0]*z[1]+y[0]*z[1]-y[0]*x[1]+z[0]*x[1]-z[0]*y[1])); 
                }
            }
        }
        return res;
    }
};
