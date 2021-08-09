#include <iostream>
#include <cstring>
#include <string>
using namespace std;
using ll = long long;
const ll M = (int)1e9 + 7;
const int MAX_N = 2010;
int a[MAX_N];
ll dp[MAX_N][2010][2]; // dp[pos][pre][even]
int m, d;

// pos:从低到高第几位，pre:数字对m取模的结果
// even==true表示当前位为偶数位，limit:最高位限制标记
ll dfs(int pos, int pre, bool even, bool limit)
{
    if (pos < 0)
        return (pre % m == 0); // 数字本身是否能被m整除
    if (~dp[pos][pre][even] && !limit)
        return dp[pos][pre][even];
    ll res = 0;
    int up = limit ? a[pos] : 9;
    for (int i = 0; i <= up; ++i)
    {
        if (!even && i == d) // 在奇数位且为d的情况
            continue;
        else if (i == d) // 在偶数位且当前位数字为d的情况
            res = (res + dfs(pos - 1, (pre * 10 + i) % m, !even, limit && i == a[pos])) % M;
        else if (!even) // 在奇数位且当前位数字不为d的情况
            res = (res + dfs(pos - 1, (pre * 10 + i) % m, !even, limit && i == a[pos])) % M;
    }
    if (!limit)
        dp[pos][pre][even] = res;
    return res;
}

ll digitalDP(string num)
{
    int len = num.size();
    for (int i = 0; i < len; ++i)
        a[i] = num[len - 1 - i] - '0';
    return dfs(len - 1, 0, false, true);
}

int main()
{
    memset(dp, -1, sizeof(dp));
    string l, r;
    cin >> m >> d >> l >> r;
    ll ans = (digitalDP(r) - digitalDP(l) + M) % M;
    int i, num;
    for (i = num = 0; i < l.size(); ++i) // 对l单独判断一下
    {
        num = (num * 10 + l[i] - '0') % m;
        if ((i & 1) != (l[i] - '0' == d))
            break;
    }
    if (i == l.size() && !num)
        ans = (ans + 1) % M;
    cout << ans << '\n';
    return 0;
}