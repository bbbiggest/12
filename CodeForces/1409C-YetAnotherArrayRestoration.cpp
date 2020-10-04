#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x, y;
        cin >> n >> x >> y;
        int diff = y - x;
        int ge;
        for (ge = 1; ge < diff; ge++)
        {
            if (diff % ge)
                continue;
            if (diff / ge + 1 > n)
                continue;
            break;
        }
        int num = min((y - 1) / ge, n - 1);
        int a0 = y - num * ge;
        for (int i = 0; i < n; i++)
            cout << (a0 + i * ge) << " ";
        cout << endl;
    }
    return 0;
}

//https://codeforces.com/problemset/problem/1409/C
