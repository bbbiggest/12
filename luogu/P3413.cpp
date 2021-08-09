// 洛谷 P3413 - 萌数
#include <iostream>
#include <cstring>
#include <string>
using namespace std;
using ll = long long;
const ll M = (int)1e9 + 7;
const int MAX_N = 1000 + 10;
int a[MAX_N];
ll dp[MAX_N][20][2]; // dp[pos][pre1][isPal]，记录pre1就够了

// pre2表示当前位往数第2位，pre1表示当前位往前数第1位
// pre1 == 10 表示前一位为前导0
// pos:从低到高第几位，limit:最高位限制标记，isPal是否含有回文串
ll dfs(int pos, int pre2, int pre1, int isPal, bool limit)
{
    if (pos < 0)
        return isPal; // 返回是否是萌数
    if (~dp[pos][pre1][isPal] && !limit)
        return dp[pos][pre1][isPal];
    ll res = 0;
    int up = limit ? a[pos] : 9;
    for (int i = 0; i <= up; ++i)
    {
        if (pre1 == 10 && !i) // 若前一位为前导0
            res = (res + dfs(pos - 1, 10, 10, 0, limit && i == a[pos])) % M;
        else
            res = (res + dfs(pos - 1, pre1, i, (isPal || i == pre1 || i == pre2), limit && i == a[pos])) % M;
    }
    if (!limit && pre1 < 10 && pre2 < 10)
        dp[pos][pre1][isPal] = res;
    return res;
}

ll digitalDP(string num)
{
    int len = num.size();
    for (int i = 0; i < len; ++i)
        a[i] = num[len - 1 - i] - '0';
    memset(dp, -1, sizeof(dp));
    return dfs(len - 1, 10, 10, 0, true) % M;
}

int main()
{
    string l, r;
    cin >> l >> r;
    ll ans = (digitalDP(r) - digitalDP(l) + M) % M; // 加M防止负数的情况
    for (int i = 1; i < l.size(); ++i) // 单独判断 l 是不是萌数
    {
        if (l[i] == l[i - 1] || (i >= 2 && l[i] == l[i - 2]))
        {
            ans = (ans + 1) % M;
            break;
        }
    }
    cout << ans << '\n';
    return 0;
}