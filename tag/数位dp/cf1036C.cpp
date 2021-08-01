#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;
ll a[20], f[20][5];

ll dfs(int pos, int num, int lim)
{
    if (pos < 0)
        return 1;
    if (lim == 0 && f[pos][num] >= 0)
        return f[pos][num];
    int up = lim ? a[pos] : 9;
    ll ans = 0;
    for (int i = 0; i <= up; i++)
    {
        if (i == 0)
            ans += dfs(pos - 1, num, lim && a[pos] == i);
        else if (num < 3)
            ans += dfs(pos - 1, num + 1, lim && a[pos] == i);
    }
    if (lim == 0)
        f[pos][num] = ans;
    return ans;
}

ll digitalDP(ll x)
{
    int tot = 0;
    while (x)
    {
        a[tot++] = x % 10;
        x /= 10;
    }
    return dfs(tot - 1, 0, 1);
}

int main()
{
    int T;
    cin >> T;
    memset(f, -1, sizeof(f));
    while (T--)
    {
        ll l, r;
        cin >> l >> r;
        cout << digitalDP(r) - digitalDP(l - 1) << '\n';
    }
    return 0;
}