class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> merge;
        int i = 0,
            j = 0,
            size1 = nums1.size(),
            size2 = nums2.size();
        double sonuc;

        while (i < size1 && j < size2)
        {
            if (nums1[i] > nums2[j])
            {
                merge.push_back(nums2[j]);
                j++;
            }
            else
            {
                merge.push_back(nums1[i]);
                i++;
            }
        }
        while (i < size1)
        {
            merge.push_back(nums1[i]);
            i++;
        }
        while (j < size2)
        {
            merge.push_back(nums2[j]);
            j++;
        }

        int msize = merge.size();
        if (msize%2 != 0)
            sonuc = merge[msize/2];
        else
             sonuc = (merge[msize/2] + merge[msize/2 - 1]) / 2.0;
        return (sonuc);
    }
};