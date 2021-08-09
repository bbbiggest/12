#include <iostream>
#include <cstring>
#include <numeric>
using namespace std;
using ll = long long;
const int MAX_N = 20;
int a[MAX_N];
ll dp[MAX_N][2520][50]; // dp[pos][pre][M]
int mp[2521]; // 字典，存每个公倍数被映射为多少

// pos:从低到高第几位，pre:数字本身，limit:最高位限制标记
// M: 每一位上的数字的最小公倍数
ll dfs(int pos, int pre, int M, bool limit)
{
    if (pos < 0)
        return (pre % M == 0);
    if (~dp[pos][pre][mp[M]] && !limit)
        return dp[pos][pre][mp[M]];
    ll res = 0;
    int up = limit ? a[pos] : 9;
    for (int i = 0; i <= up; ++i)
    {
        if (!i) // 0的情况特殊处理一下
            res += dfs(pos - 1, (pre * 10 + i) % 2520, M, limit && i == a[pos]);
        else
            res += dfs(pos - 1, (pre * 10 + i) % 2520, lcm(M, i), limit && i == a[pos]);
    }
    if (!limit)
        dp[pos][pre][mp[M]] = res;
    return res;
}

ll digitalDP(ll num)
{
    int len;
    for (len = 0; num; num /= 10)
        a[len++] = num % 10;
    return dfs(len - 1, 0, 1, true);
}

int main()
{
    int cnt = 0;
    for (int i = 1; i <= 2520; ++i) // 预处理，将每个可能的公倍数映射为0~47
        if (2520 % i == 0)
            mp[i] = cnt++;
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