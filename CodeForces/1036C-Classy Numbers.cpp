#include <iostream>
#include <cstring>
using namespace std;
using ll = long long;
const int MAX_N = 20;
int a[MAX_N];
ll dp[MAX_N][5]; // dp[pos][cnt]

// pos:从低到高第几位，cnt:当前出现的非0数字的个数，limit:最高位限制标记
ll dfs(int pos, int cnt, bool limit)
{
    if (pos < 0)
        return 1;
    if (~dp[pos][cnt] && !limit)
        return dp[pos][cnt];
    ll res = 0;
    int up = limit ? a[pos] : 9;
    for (int i = 0; i <= up; ++i)
    {
        if (!i) // 0特殊处理一下
            res += dfs(pos - 1, cnt, limit && i == a[pos]);
        else if (cnt < 3) // 如果还没超过3个数字
            res += dfs(pos - 1, cnt + 1, limit && i == a[pos]);
    }
    if (!limit)
        dp[pos][cnt] = res;
    return res;
}

ll digitalDP(ll num)
{
    int len;
    for (len = 0; num; num /= 10)
        a[len++] = num % 10;
    return dfs(len - 1, 0, true);
}

int main()
{
    memset(dp, -1, sizeof(dp));
    int t;
    cin >> t;
    while (t--)
    {
        ll l, r;
        cin >> l >> r;
        cout << digitalDP(r) - digitalDP(l - 1) << '\n'; // 差分
    }
    return 0;
}