#include <queue>
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        queue<int> odd;///保存奇数
        queue<int>even;///保存偶数
        for (auto& iter : nums) {
            if (0 == iter % 2) {
                even.push(iter);
            }
            else {
                odd.push(iter);
            }
        }

        vector<int> result;
        result.reserve(odd.size() + even.size());
        while (!even.empty()) {
            result.push_back(even.front());
            even.pop();
        }
        while (!odd.empty()) {
            result.push_back(odd.front());
            odd.pop();
        }
        return result;
    }
};