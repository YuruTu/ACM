#include <iostream>


using namespace std;


int main() {

    long long n, s;
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> s;
        long long result = s / (n * n);
        cout << result << endl;
    }



    return 0;
}