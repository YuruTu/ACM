class Solution {
public:
    /// 基于动态规划，求解该题
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = static_cast<int>(mat.size());
        int n = static_cast<int>(mat[0].size());
        vector<vector<int>> result(m);
        for (int i = 0; i < m; ++i) {
            result[i].resize(n, 100000);
        }
        /// 先给有0的地方复初值
        for (int row = 0; row < m; ++row) {
            for (int col = 0; col < n; ++col) {
                if (0 == mat[row][col])
                {
                    result[row][col] = 0;
                }
            }
        }
        /// 先水平
        for (int row = 0; row < m; ++row) {
            for (int col = 0; col < n; ++col) {
                if (row - 1 >= 0) {
                    result[row][col] = min(result[row][col], result[row - 1][col] + 1);
                }
                if (col - 1 >= 0) {
                    result[row][col] = min(result[row][col], result[row][col - 1] + 1);
                }
            }
        }
        for (int row = m - 1; row >= 0; --row) {
            for (int col = n - 1; col >= 0; --col) {
                if (row + 1 < m) {
                    result[row][col] = min(result[row][col], result[row + 1][col] + 1);
                }
                if (col + 1 < n) {
                    result[row][col] = min(result[row][col], result[row][col + 1] + 1);
                }
            }
        }

        return result;

    }
};