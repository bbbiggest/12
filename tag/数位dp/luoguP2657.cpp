#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
const int MAX_N = 20;
int a[MAX_N];
int dp[MAX_N][20];

int dfs(int pos, int pre, bool limit)
{
    if (pos < 0)
        return 1;
    if (~dp[pos][pre] && !limit)
        return dp[pos][pre];
    int res = 0;
    int high = limit ? a[pos] : 9;
    for (int i = 0; i <= high; ++i)
    {
        if (abs(pre - i) < 2)
            continue;
        if (pre == 11 && !i)
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
    if (num < 0)
        return 0;
    int len;
    for (len = 0; num; num /= 10)
        a[len++] = num % 10;
    memset(dp, -1, sizeof(dp));
    return dfs(len - 1, 11, true);
}

int main()
{
    int a, b;
    cin >> a >> b;
    cout << digitalDP(b) - digitalDP(a - 1) << '\n';
    return 0;
}