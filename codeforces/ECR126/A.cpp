#include <iostream>
#include <cmath>
using namespace std;
int const NMAX = 30;
long a[NMAX];
long b[NMAX];


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }

        long  long sumV = 0;
        for (int i = 0; i < (n - 1); ++i) {
            ///<È·ÈÏÊÇ·ñswap
            long  long  temp0 = std::abs(a[i] - a[i + 1]) + std::abs(b[i] - b[i + 1]);
            long  long temp1 = std::abs(a[i] - b[i + 1]) + std::abs(b[i] - a[i + 1]);
            if (temp0 > temp1) {
                std::swap(a[i + 1], b[i + 1]);
                sumV += temp1;
            }
            else {
                sumV += temp0;
            }
            
        }
        std::cout << sumV << std::endl;


    }



    return 0;
}