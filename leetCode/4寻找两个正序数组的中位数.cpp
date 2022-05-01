class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        int mSize = static_cast<int>(nums1.size());
        int nSize = static_cast<int>(nums2.size());
        int allSize = mSize + nSize;
        result.reserve(allSize);
        int m = 0, n = 0;
        while ((m < mSize) && (n < nSize)) {
            if (nums1[m] < nums2[n]) {
                result.push_back(nums1[m]);
                ++m;
            }
            else {
                result.push_back(nums2[n]);
                ++n;
            }
        }
        if ((m == mSize) && (n < nSize)) {
            for (int i = n; i < nSize; ++i) {
                result.push_back(nums2[i]);
            }
        }
        else if ((m < mSize) && (n == nSize)) {
            for (int i = m; i < mSize; ++i) {
                result.push_back(nums1[i]);
            }
        }
        double ans;
        int temp = allSize >> 1;
        if (0 == allSize % 2) {
            ans = 0.5 * (result[temp] + result[temp - 1]);
        }
        else {
            ans = result[temp];
        }
        return ans;

    }
};