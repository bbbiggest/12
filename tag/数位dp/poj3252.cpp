#include <iostream>
#include <cstring>
using namespace std;
int dp[40][40][40];
int dig[12];
int dfs(int pos, int num0, int num1, int limit, int fzore)
{
    if (!pos)
        return num0 >= num1;
    if (!limit && ~dp[pos][num0][num1])
        return dp[pos][num0][num1];
    int len = limit ? dig[pos] : 1;
    int ans = 0;
    for (int i = 0; i <= len; i++)
    {
        if (!fzore)
        {
            if (i)
                ans += dfs(pos - 1, num0, num1 + 1, limit && i == len, fzore && !i);
            else
                ans += dfs(pos - 1, num0 + 1, num1, limit && i == len, fzore && !i);
        }
        else
        {
            if (i)
                ans += dfs(pos - 1, num0, num1 + 1, limit && i == len, fzore && !i);
            else
                ans += dfs(pos - 1, num0, num1, limit && i == len, fzore && !i);
        }
    }
    if (!limit)
        dp[pos][num0][num1] = ans;
    return ans;
}
int digitalDP(int x)
{
    int len = 0;
    while (x)
    {
        dig[++len] = x % 2;
        x /= 2;
    }
    return dfs(len, 0, 0, 1, 1);
}
int main()
{
    int a, b;
    while (cin >> a >> b)
    {
        memset(dp, -1, sizeof(dp));
        cout << digitalDP(b) - digitalDP(a - 1) << '\n';
    }
    return 0;
}