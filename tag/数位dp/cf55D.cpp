#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;
const int M = 2520;
ll index[M + 3];
ll dp[22][M][50];
int num[20];

ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
ll lcm(ll a, ll b)
{
    return a / gcd(a, b) * b;
}

ll dfs(int pos, int pre, int now, bool limit)
{
    if (pos == -1)
    {
        if (now % pre == 0)
            return 1;
        return 0;
    }
    if (!limit && dp[pos][now][index[pre]] != -1)
        return dp[pos][now][index[pre]];
    int up = limit ? num[pos] : 9;
    ll ret = 0;
    for (int i = 0; i <= up; i++)
    {
        int next = (now * 10 + i) % M;
        int tlcm = pre;
        if (i)
            tlcm = lcm(tlcm, i);
        ret += dfs(pos - 1, tlcm, next, limit && i == up);
    }
    if (!limit)
        dp[pos][now][index[pre]] = ret;
    return ret;
}
ll digitalDP(ll x)
{
    if (x == 0)
        return 1;
    int ind = 0;
    memset(num, 0, sizeof(num));
    while (x)
    {
        num[ind++] = x % 10;
        x /= 10;
    }
    return dfs(ind - 1, 1, 0, true);
}
int main()
{
    int cnt = 0;
    for (int i = 1; i <= M; i++)
    {
        if (M % i == 0)
            index[i] = cnt++;
    }
    memset(dp, -1, sizeof(dp));
    int t;
    cin >> t;
    while (t--)
    {
        ll l, r;
        cin >> l >> r;
        cout << digitalDP(r) - digitalDP(l - 1) << '\n';
    }
    return 0;
}