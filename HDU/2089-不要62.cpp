#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;
const int MAX_N = 20;
int a[MAX_N];
int dp[MAX_N][2]; // dp[pos][st] 表示从低到高第pos位数，(st==1)表示前一位数为6

// pos:从低到高第几位，st:(前一位==4)，limit:最高位限制标记
int dfs(int pos, int st, bool limit)
{
    if (pos < 0)
        return 1;
    if (~dp[pos][st] && !limit)
        return dp[pos][st];
    int res = 0;
    int up = limit ? a[pos] : 9;
    for (int i = 0; i <= up; ++i)
    {
        if (i == 4) // 出现4的情况
            continue;
        if (st && i == 2) // 前一位为6且当前位位2的情况
            continue;
        res += dfs(pos - 1, i == 6, limit && i == a[pos]);
    }
    if (!limit)
        dp[pos][st] = res;
    return res;
}

int digitalDP(int num)
{
    if (num < 0) // 若为-1直接返回0即可
        return 0;
    int len;
    for (len = 0; num; num /= 10)
        a[len++] = num % 10;
    return dfs(len - 1, 0, true);
}

int main()
{
    memset(dp, -1, sizeof(dp));
    int n, m;
    while (cin >> n >> m && m)
        cout << digitalDP(m) - digitalDP(n - 1) << '\n'; // 差分
    return 0;
}