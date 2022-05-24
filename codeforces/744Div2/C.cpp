#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const unsigned long long maxNum = 1e12;

unsigned long long getSetBits(unsigned long long n)
{
    unsigned long long cnt = 0;
    while (0!=n)
    {
        cnt += n & 1;
        n >>= 1;
    }
    return cnt;
}

class CDPSolver {
public:
    CDPSolver() {
        unsigned long long fact = 1;
        m_powerful.push_back(fact);
        for (int i = 2;; ++i) {
            fact *= i;
            if (fact > maxNum)
                break;
            m_powerful.push_back(fact);
        }
        m_powerfulSize = static_cast<int>(m_powerful.size());
    }

    int solve(unsigned long long n,int i) {
        if (n < 0)
            return INT_MAX;
        if (i >= m_powerfulSize)
            return getSetBits(n);
        if (n == 0)
            return 0;

        int ans = INT_MAX;

        ans = std::min(1 + solve(n - m_powerful[i], i + 1), solve(n, i + 1));

        return ans;
    }


private:
    std::vector<unsigned long long> m_powerful;
    int                             m_powerfulSize;
};



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<unsigned long long> powerfulNums;
    CDPSolver pSover;
    int powerfulSize = static_cast<int>(powerfulNums.size());
    int t;
    cin >> t;
    unsigned long long n;
    while (t--) {
        cin >> n;
        int ans = pSover.solve(n, 0);

        std::cout << ans << endl;


    }



    return 0;
}