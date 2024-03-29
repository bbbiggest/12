#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;
const int MAX_N = 20;
int a[MAX_N];
ll dp[MAX_N][2]; // dp[pos][st] 表示从低到高第pos位数，(st==1)表示前一位数为4

// pos:从低到高第几位，st:(前一位==4)，limit:最高位限制标记
ll dfs(int pos, bool st, bool limit)
{
    if (pos < 0)
        return 1;
    if (~dp[pos][st] && !limit)
        return dp[pos][st];
    ll res = 0;
    int up = limit ? a[pos] : 9;
    for (int i = 0; i <= up; ++i)
    {
        if (st && i == 9) // 若前一位为4且当前位为9
            continue;
        res += dfs(pos - 1, i == 4, limit && i == a[pos]);
    }
    if (!limit)
        dp[pos][st] = res;
    return res;
}

ll digitalDP(ll num)
{
    int len;
    for (len = 0; num; num /= 10)
        a[len++] = num % 10;
    return dfs(len - 1, false, true);
}

int main()
{
    memset(dp, -1, sizeof(dp));
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        cout << n - (digitalDP(n) - 1) << '\n'; // 减去 0 的情况
    }
    return 0;
}