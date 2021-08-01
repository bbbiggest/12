#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;
const int MAX_N = 20;
int a[MAX_N];
ll dp[MAX_N][2];

ll dfs(int pos, int st, bool limit)
{
    if (pos < 0)
        return 1;
    if (~dp[pos][st] && !limit)
        return dp[pos][st];
    ll res = 0;
    int high = limit ? a[pos] : 9;
    for (int i = 0; i <= high; ++i)
    {
        if (st && i == 9)
            continue;
        res += dfs(pos - 1, i == 4, limit && i == a[pos]);
    }
    if (!limit)
        dp[pos][st] = res;
    return res;
}

ll digitalDP(ll num)
{
    if (num < 0)
        return 0;
    int len;
    for (len = 0; num; num /= 10)
        a[len++] = num % 10;
    memset(dp, -1, sizeof(dp));
    return dfs(len - 1, 0, true);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        cout << n - digitalDP(n) + 1 << '\n';
    }
    return 0;
}