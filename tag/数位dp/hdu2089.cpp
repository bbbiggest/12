#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;
const int MAX_N = 20;
int a[MAX_N];
int dp[MAX_N][2];

int dfs(int pos, int st, bool limit)
{
    if (pos < 0)
        return 1;
    if (~dp[pos][st] && !limit)
        return dp[pos][st];
    int res = 0;
    int high = limit ? a[pos] : 9;
    for (int i = 0; i <= high; ++i)
    {
        if (i == 4)
            continue;
        if (st && i == 2)
            continue;
        res += dfs(pos - 1, i == 6, limit && i == a[pos]);
    }
    if (!limit)
        dp[pos][st] = res;
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
    return dfs(len - 1, 0, true);
}

int main()
{
    int n, m;
    while (cin >> n >> m && m)
        cout << digitalDP(m) - digitalDP(n - 1) << '\n';
    return 0;
}