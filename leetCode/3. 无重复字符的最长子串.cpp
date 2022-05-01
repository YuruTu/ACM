class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int nSize = static_cast<int>(s.size());
        int ans;
        for (int i = 0; i < nSize; ++i) {
            map<char, int> maps;
            int nCount = 0;
            for (int start = i; start < nSize; ++start) {
                auto iter = maps.find(s[start]);
                if (maps.end() == iter) {
                    maps[s[start]] = 1;
                    ++nCount;
                }
                else {
                    if (nCount > ans)
                        ans = nCount;
                    break;
                }
            }
            if (nCount > ans)
                ans = nCount;
        }

        return ans;

    }

};
