class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {

        /// 只考虑顺序情况的极值
        int n = nums.size();
        if (1 == n)
            return nums[0];
        int ans = maxSubArray(nums);
        int ans1 = nums[0];
        int maxId = 0;
        int maxV = integralArr[1];
        for (int i = 1; i < n; ++i) {
            maxV = max(maxV, integralArr[i]);
            ans1 = min(ans1, integralArr[i + 1] - maxV);
        }
        ans1 = integralArr[n] - ans1;
        ans = max(ans1, ans);
        return ans;
    }

    /// 
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        integralArr.resize(n + 1, 0);
        integralArr[0] = 0;
        for (int i = 0; i < n; ++i) {
            integralArr[i + 1] = integralArr[i] + nums[i];
        }

        int ans = nums[0];
        int minId = 0;
        int minV = integralArr[0];
        for (int i = 0; i < n; ++i) {

            minV = min(minV, integralArr[i]);
            ans = max(ans, integralArr[i + 1] - minV);

        }
        return ans;

    }
private:
    vector<int> integralArr;

};