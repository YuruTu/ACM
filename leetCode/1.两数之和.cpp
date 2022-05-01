#include <map>

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> maps;
        vector<int> result;
        int nSize = static_cast<int>(nums.size());
        for (int i = 0; i < nSize; ++i) {
            maps[nums[i]] = i;
        }
        for (int i = 0; i < nSize; ++i) {
            int temp = target - nums[i];
            auto iter = maps.find(temp);
            if (maps.end() != iter) {
                if (iter->second == i)
                    continue;
                result.push_back(i);
                result.push_back(iter->second);
                return result;
            }
        }
        return result;
    }
};