#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;
const int MAX_N = 32; // 二进制整数也就32位
int a[MAX_N];
int dp[MAX_N][64];

// pos:从低到高第几位，st:32为初始值，遇到0加一，遇到1减一
// lead:前导0标记，limit:最高位限制标记
int dfs(int pos, int st, bool lead, bool limit)
{
    if (pos < 0)
        return (st >= 32); // 0的数量大于等于1的数量
    if (~dp[pos][st] && !limit && !lead)
        return dp[pos][st];
    int res = 0;
    int up = limit ? a[pos] : 1; // 这里注意二进制最高为1
    for (int i = 0; i <= up; ++i)
    {
        if (!i && lead) // 前一位为前导0
            res += dfs(pos - 1, st, true, limit && i == a[pos]);
        else // 如果i为0，st就加一；i为1就减一
            res += dfs(pos - 1, st + (i ? -1 : 1), false, limit && i == a[pos]);
    }
    if (!limit && !lead)
        dp[pos][st] = res;
    return res;
}

int digitalDP(int num)
{
    int len;
    for (len = 0; num; num >>= 1) // 二进制
        a[len++] = num & 1;
    memset(dp, -1, sizeof(dp));
    return dfs(len - 1, 32, true, true);
}

int main()
{
    int a, b;
    cin >> a >> b;
    cout << digitalDP(b) - digitalDP(a - 1) << '\n';
    return 0;
}