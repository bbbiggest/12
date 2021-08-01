#include <iostream>
#include <cstring>
#include <string>
using namespace std;
typedef long long ll;
const ll M = 1e9 + 7;
const int MAX_N = 2020;
int dg[MAX_N];
ll f[MAX_N][MAX_N];
int m, n;

inline ll add(ll x, ll y)
{
    x = x + y;
    return x >= M ? x - M : x;
}

ll dfs(int i, int s, bool flag, bool e)
{
    if (i == -1)
        return s == 0;
    if (!e && ~f[i][s])
        return f[i][s];
    ll res = 0ll;
    int u = e ? dg[i] : 9;
    for (int d = 0; d <= u; ++d)
    {
        if (flag == 1 && d == n)
            continue;
        if (flag == 0 && d != n)
            continue;
        res = add(res, dfs(i - 1, (s * 10 + d) % m, flag ^ 1, e && d == u));
    }
    return e ? res : f[i][s] = res;
}

void deal(int &len)
{
    for (int i = 0; i < len; ++i)
    {
        if (dg[i] == 0)
            dg[i] = 9;
        else
        {
            --dg[i];
            break;
        }
    }
    return;
}

ll digitalDP(string c, bool fg)
{
    int len = c.size();
    for (int i = 0; i < len; ++i)
        dg[i] = c[len - 1 - i] - '0';
    if (fg)
        deal(len);
    return dfs(len - 1, 0, 1, 1);
}

int main()
{
    string a, b;
    cin >> m >> n >> a >> b;
    memset(f, -1, sizeof(f));
    cout << add(digitalDP(b, false) - digitalDP(a, true), M) << '\n';
    return 0;
}