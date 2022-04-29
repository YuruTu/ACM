/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    /// 使用递归算法
    Node* dfs(int r0, int c0, int r1, int c1) {

        int temp = m_gridInt[r1][c1] - m_gridInt[r1][c0] - \
            m_gridInt[r0][c1] + m_gridInt[r0][c0];
        int S = (r1 - r0) * (c1 - c0);
        if ((temp == S) || (0 == temp))
            // 是叶节点
            return new Node(m_grid[r0][c0], true);
        return new Node(
            true,
            false,
            dfs(r0, c0, (r0 + r1) / 2, (c0 + c1) / 2),
            dfs(r0, (c0 + c1) / 2, (r0 + r1) / 2, c1),
            dfs((r0 + r1) / 2, c0, r1, (c0 + c1) / 2),
            dfs((r0 + r1) / 2, (c0 + c1) / 2, r1, c1)
        );
    }


    Node* construct(vector<vector<int>>& grid) {
        m_grid = grid;
        m_gridInt = m_grid;
        int nSize = static_cast<int>(m_gridInt.size());
        m_gridInt.resize(nSize + 1);
        for (int i = 0; i <= nSize; ++i)
            m_gridInt[i].resize(nSize + 1);
        /// 先给第一行和第一列赋值
        for (int row = 0; row <= nSize; ++row) {
            m_gridInt[row][0] = 0;
        }
        for (int col = 1; col < nSize; ++col) {
            m_gridInt[0][col] = 0;
        }
        for (int row = 0; row < nSize; ++row) {
            for (int col = 0; col < nSize; ++col) {
                m_gridInt[row + 1][col + 1] = m_grid[row][col] + m_gridInt[row][col + 1] + \
                    m_gridInt[row + 1][col] - m_gridInt[row][col];
            }
        }
        return this->dfs(0, 0, nSize, nSize);

    }
private:
    vector<vector<int>> m_grid;
    vector<vector<int>> m_gridInt;
};