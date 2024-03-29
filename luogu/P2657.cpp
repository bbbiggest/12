// 洛谷P2657 - windy 数
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
using ll = long long;
const int MAX_N = 20;
int a[MAX_N];
int dp[MAX_N][20]; // dp[pos][pre]保存从低到高第pos位数且前一位数为pre的情况数量

// pos:从低到高第几位，pre:前一位上的数字，limit:最高位限制标记
// pre为11表示前一位是前导0
int dfs(int pos, int pre, bool limit)
{
    if (pos < 0)
        return 1;
    if (~dp[pos][pre] && !limit)
        return dp[pos][pre];
    int res = 0;
    int up = limit ? a[pos] : 9;
    for (int i = 0; i <= up; ++i)
    {
        if (abs(pre - i) < 2) // 与前一位数之差小于2的情况
            continue;
        if (pre == 11 && !i) // 前一位是前导0的情况
            res += dfs(pos - 1, 11, limit && i == a[pos]);
        else
            res += dfs(pos - 1, i, limit && i == a[pos]);
    }
    if (!limit)
        dp[pos][pre] = res;
    return res;
}

int digitalDP(int num)
{
    int len;
    for (len = 0; num; num /= 10)
        a[len++] = num % 10;
    return dfs(len - 1, 11, true);
}

int main()
{
    memset(dp, -1, sizeof(dp));
    int a, b;
    cin >> a >> b;
    cout << digitalDP(b) - digitalDP(a - 1) << '\n'; // 差分
    return 0;
}