#include <iostream>
#include <algorithm>

using namespace std;

long long a[2 * 100 * 1000 + 1];
int main() {

    int n;
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        sort(a, a + n);
        ///<n必然大于3
        long long sumA = 0;
        long long sumB = 0;
        bool flag = false;
        if (0 == (n % 2)) {
            sumA += a[0];
            sumA += a[1];
            for (int i = 2; i <= (n >> 1); ++i) {
            
                sumB += a[n + 1 - i];
                if (sumA < sumB) {
                    flag = true;
                    break;
                }
                sumA += a[i];
                
            }
        }
        else {
            sumA += a[0];
            for (int i = 1; i <= (n >> 1); ++i) {
                sumA += a[i];
                sumB += a[n  - i];
                if (sumA < sumB) {
                    flag = true;
                    break;
                }
            }
        }
        
        if (flag) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }

    }



    return 0;
}