#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


const int NMAX = 105;
int a[NMAX];
int b[NMAX];


struct MData {
    int a;
    int b;
    int id;
};

static bool cmp(MData const& L, MData const& R) {
    if (L.a < R.a)
        return true;
    if (L.a > R.a)
        return false;
    if (L.a == R.a)
        return L.b < R.b;
}

int get_pos(MData* a, int x, int n)
{
    for (int i = x; i < n; i++)
    {
        if (a[i].id == x) return i;
    }
}
int leftarr[10000 + 5];
int rightarr[10000 + 5];
void run(MData* array, int n)
{

    int count = 0;
    int pos = 0;

    for (int i = 0; i < n; i++)
    {
        //数组值与其对应的下标值相等 
        if (i == array[i].id)  continue;
        else
        {
            //获得和下标值相等的数组值的索引(位置) 
            pos = get_pos(array, i, n);
            swap(array[i], array[pos]);
            leftarr[count] = array[i].id + 1;
            rightarr[count] = array[pos].id + 1;
            ++count;
        }
    }
    cout << count << endl;
    for (int i = 0; i < count; ++i) {
        cout << leftarr[i] << " " << rightarr[i] << endl;
    }
}



MData mData[NMAX];
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
        ///  先判断能否交换成功
        for (int i = 0; i < n; ++i) {
            mData[i].a = a[i];
            mData[i].b = b[i];
            mData[i].id = i;
        }
        sort(mData, mData + n, cmp);
        bool flag = true;
        for (int i = 0; i < n - 1; ++i) {
            if (mData[i].b > mData[i + 1].b) {
                flag = false;
                break;
            }
        }
        if (!flag) {
            cout << "-1" << endl;
        }
        else {
            run(mData, n);
        }
    }

    return 0;
}