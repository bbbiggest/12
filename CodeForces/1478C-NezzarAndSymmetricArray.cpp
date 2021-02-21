#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
const int MAX_N = 200010;
ll d[MAX_N], ra[MAX_N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        for (int i = 0; i < 2 * n; ++i)
            cin >> d[i];
        sort(d, d + 2 * n);
        bool okk = true;
        for (int i = 0; okk & i < 2 * n; i += 2)
        {
            if ((d[i] != d[i + 1]) || (d[i] & 1ll))
                okk = false;
            else if (i >= 2 && d[i] == d[i - 2])
                okk = false;
            else if (i >= 2 && (d[i] - d[i - 2]) % i)
                okk = false;
            if (i >= 2)
                ra[i / 2] = (d[i] - d[i - 2]) / i;
        }
        if (!okk)
        {
            cout << "NO\n";
            continue;
        }
        ll a0 = d[0];
        for (int i = 1; i < n; ++i)
            a0 -= ra[i] * (n - i) * 2;
        if (a0 % (ll)n)
        {
            cout << "NO\n";
            continue;
        }
        a0 /= n;
        if (a0 % 2 == 0 && a0 / 2 > 0)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    cout.flush();
    return 0;
}
