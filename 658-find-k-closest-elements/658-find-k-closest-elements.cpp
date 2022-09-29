class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> ans;
        
        int minIdx = minIndex(arr, x);
        ans.push_back(arr[minIdx]);
        k--;
        
        int left = minIdx-1;
        int right = minIdx+1;
        
        while (k > 0)
        {
            int cIdx = closestElement(arr, left, right, x);
            if (cIdx == left-1)
            {
                ans.push_back(arr[left]);
                left = cIdx;
            }
            else
            {
                ans.push_back(arr[right]);
                right = cIdx;
            }
            k--;
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
    
    // find the smallest Value index
    int minIndex(vector<int>& arr, int x)
    {
        int minIdx = 0;
        int minVal = abs(arr[0]-x);
        
        for (int i = 1; i < arr.size(); i++)
        {
            if (minVal > abs(arr[i]-x))
            {                
                minIdx = i;
                minVal = abs(arr[i]-x);
            }
        }
        return minIdx;
    } 
    
    // Apply the constraints
    int closestElement(vector<int>& arr, int left, int right, int x)
    {
        if (left < 0)
            return right+1;
        else if (right == arr.size())
            return left-1;
        else if (abs(arr[left]-x) < abs(arr[right]-x) ||
                (abs(arr[left]-x) == abs(arr[right]-x) && arr[left] < arr[right]))
        {
            return left-1;
        }
        else
            return right+1;
            
    }
};