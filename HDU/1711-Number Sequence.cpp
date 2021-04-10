#include <iostream>
using namespace std;
using ull = unsigned long long;
const ull B = 100000007;
const int MAX_N = 1000000 + 10;
const int MAX_M = 10000 + 10;
int a[MAX_N], b[MAX_M];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        ull t = 1, bh = 0;
        for (int i = 0; i < m; ++i)
        {
            cin >> b[i];
            t *= B;
            bh = bh * B + b[i];
        }
        ull ah = 0;
        for (int i = 0; i < m; ++i)
            ah = ah * B + a[i];
        int ans = -1;
        for (int i = 0; i + m <= n; ++i)
        {
            if (ah == bh)
            {
                ans = i + 1;
                break;
            }
            if (i + m < n)
                ah = ah * B + a[i + m] - a[i] * t;
        }
        cout << ans << '\n';
    }
    cout.flush();
    return 0;
}