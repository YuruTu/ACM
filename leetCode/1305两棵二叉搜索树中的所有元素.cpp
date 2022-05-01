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
#include <queue>
using namespace std;
class Solution {
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        std::queue<int>  mQueue1, mQueue2;
        PreOrder(root1, mQueue1);
        PreOrder(root2, mQueue2);
        vector<int> result;
        result.reserve(mQueue1.size() + mQueue2.size());
        for (auto iter = mQueue1.front() iter != mQueue1.end(); iter++) {
            result.push_back(iter->val);
        }
        for (auto iter = mQueue2.begin(); iter != mQueue2.end(); iter++) {
            result.push_back(iter->val);
        }

        sort(result.begin(), result.end());
        return result;
    }
};